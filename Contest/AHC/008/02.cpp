#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

#define INF 1100100100

// 行動をintで表す
using Action = string;
using EnemyAction = vector<string>;

#define Empty 0 // 通行可能
#define Ushi  1 // 牛
#define Buta  2 // 豚
#define Usagi 3 // 兎 
#define Inu   4 // 犬
#define Neko  5 // 猫
#define Hito  6 // 人
#define Wall  7 // 通行不可

/* 各種ペットについてループするときに用いる */
vector<int> animal_list = {Ushi, Buta, Usagi, Inu, Neko};

/* 
クラスHumanに用いる列挙体
Normal: 何もせずその場にとどまる
Greedy: 隣接するマスに壁を設置可能な場所があれば設置し、なければその場にとどまる
Move  : (dx, dy)に最短距離で移動しようとする
Place : direction方向に現在位置から壁を設置する
*/
enum class Policy {
	Normal,
	Greedy,
	Move,
	Place
};

class Pet {
public:
	// 変数
	int x, y; // 座標
	int type; // ペットの種類
	// メンバ関数
	Pet(int x, int y, int type) : x(x), y(y), type(type) {}; // コンストラクタ
};

class Human {
public:
	// 変数
	int x, y; // 座標
	Policy policy = Policy::Normal; // 行動ポリシー
	int dx, dy; // 目的の座標
	string direction = "."; // 目標座標から壁を設置する方向
	// メンバ関数
	Human(int x, int y) : x(x), y(y) {};
};

class Pattern {
private:
	int done = false;
	vector<string> pattern = {
		"##############################",
		"##############################",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		"..............................",
		".............................."
	};
public:
	int x = 0, y = 0; // 次に壁を置く位置
	Pattern(); // コンストラクタ
	bool isDone() const; // すでにパターンが完成したか
	void next(); // (x, y)を次のマスへ更新
	void next_pos(); // 次の壁を設置する場所まで(x, y)を更新する
};

Pattern::Pattern() {
	if (pattern[x][y] == '#') return;
	next_pos();
}

bool Pattern::isDone() const {
	return done;
}

void Pattern::next() {
	if (done) return;
	if (y < 29) y++;
	else {
		x++;
		y = 0;
	}
	if (x == 30) done = true;
}

void Pattern::next_pos() {
	while (!done && pattern[x][y] == '.') next();
}

class State {
private:
	bool isValid(int x, int y) const; // (x, y)が範囲内に属するか
public:
	// 変数
	int time = 0; // ゲーム内時間
	int num_pets; // ペットの数
	int num_humans; // 人の数
	vector<vector<vector<int>>> bd; // ボードの状態を持つ
	vector<Pet> pets; // ペットの座標と種類
	vector<Human> humans; // 人の座標
	Pattern pattern;
	// メンバ関数
	State(); // コンストラクタ
	bool isDone() const; // ゲームの終了判定
	void setPolicy(); // 行動ポリシーの決定
	vector<vector<int>> floodFill(int x, int y) const; // (x, y)から幅優先探索
	string route(int x, int y, int dx, int dy) const; // (x, y)から(dx, dy)まで移動するときの最初の移動方向
	string route(int index) const; // humans[i]がその目的地まで行くときの最初の移動方向
	void advance(const Action& action, const EnemyAction& enemy_action); // 指定したactionでゲームを1ターン進める
	bool isAnimal(int x, int y) const; // (x, y)に動物が存在するか
	bool canPlaceWall(int x, int y) const; // (x, y)に壁を設置可能か
	bool canPlaceWall(int index, string direction) const; // humans[i]はdirection方向に移動可能か
	bool canMove(int x, int y) const; // (x, y)に移動可能か
	bool canMove(int index, string direction) const; // humans[i]はdirection方向に移動可能か
	void out() const;
};

State::State() {
	bd.assign(30, vector<vector<int>>(30, vector<int>(8, 0)));
	cin >> num_pets;
	rep(i, num_pets) {
		int px, py, pt;
		cin >> px >> py >> pt;
		px--; py--;
		Pet t(px, py, pt);
		pets.push_back(t);
		bd[px][py][pt]++;
	}
	cin >> num_humans;
	rep(i, num_humans) {
		int hx, hy;
		cin >> hx >> hy;
		hx--; hy--;
		Human t(hx, hy);
		humans.push_back(t);
		bd[hx][hy][Hito]++;
	}
}

void State::setPolicy() {
	/* ヒトの行動ポリシーなどを設定 */
	rep(i, num_humans) {
		if (humans[i].policy == Policy::Normal) {
			if (!pattern.isDone()) {
				humans[i].dx = pattern.x + 1; // 目標位置の一つ下へ移動
				humans[i].dy = pattern.y;
				humans[i].direction = "u";
				humans[i].policy = Policy::Move;
				pattern.next();
				pattern.next_pos();
			}
		}
	}
}

bool State::isValid(int x, int y) const {
	// (x, y)が範囲内に属するか
	if (x < 0 || 30 <= x) return false;
	if (y < 0 || 30 <= y) return false;
	return true;
}

bool State::isDone() const {
	/* ゲームの終了判定 */
	if (time >= 300) return true;
	return false;
}

vector<vector<int>> State::floodFill(int x, int y) const {
	/* (x, y)から幅優先探索を行う */
	vector<vector<int>> memo(30, vector<int>(30, INF));
	queue<tuple<int, int, int>> que;
	que.emplace(x, y, 0);
	while (!que.empty()) {
		int tx, ty, d;
		tie(tx, ty, d) = que.front(); que.pop();
		if (!isValid(tx, ty)) continue; // 範囲外は無視
		if (memo[tx][ty] != INF) continue; // 訪問済みのマスは無視
		if (bd[tx][ty][Wall] > 0) continue; // 壁のあるマスは無視
		memo[tx][ty] = d; // (tx, ty)を訪問済みに
		// 上下左右のマスをqueに追加
		que.emplace(tx - 1, ty, d + 1);
		que.emplace(tx + 1, ty, d + 1);
		que.emplace(tx, ty - 1, d + 1);
		que.emplace(tx, ty + 1, d + 1);
	}
	return memo;
}

string State::route(int x, int y, int dx, int dy) const {
	/* (x, y)から(dx, dy)までの最短ルートで向かう時の最初の移動方向 */
	vector<vector<int>> memo = floodFill(dx, dy);
	if (memo[x][y] == -1) {
		cout << "Path to coordinates (dx, dy) does not exist." << endl;
		return ".";
	}
	int now = 100000;
	string ret = "";
	if (isValid(x - 1, y) && memo[x - 1][y] < now) { now = memo[x - 1][y]; ret = "U"; }
	if (isValid(x + 1, y) && memo[x + 1][y] < now) { now = memo[x + 1][y]; ret = "D"; }
	if (isValid(x, y - 1) && memo[x][y - 1] < now) { now = memo[x][y - 1]; ret = "L"; }
	if (isValid(x, y + 1) && memo[x][y + 1] < now) { now = memo[x][y + 1]; ret = "R"; }
	if (ret == "") {
		printf("there's no direction for (%d, %d) from (%d, %d).\n", dx, dy, x, y);
	}
	return ret;
}

string State::route(int index) const {
	return route(humans[index].x, humans[index].y, humans[index].dx, humans[index].dy);
}

void State::advance(const Action& action, const EnemyAction& enemy_action) {
	/* 指定したアクションでゲームを1ターン進める */
	rep(i, num_humans) {
		if (action[i] == '.') continue;
		else if (action[i] == 'u') {
			bd[humans[i].x - 1][humans[i].y][Wall]++;
			if (humans[i].policy == Policy::Place) humans[i].policy = Policy::Normal;
		}
		else if (action[i] == 'd') {
			bd[humans[i].x + 1][humans[i].y][Wall]++;
			if (humans[i].policy == Policy::Place) humans[i].policy = Policy::Normal;
		}
		else if (action[i] == 'l') {
			bd[humans[i].x][humans[i].y - 1][Wall]++;
			if (humans[i].policy == Policy::Place) humans[i].policy = Policy::Normal;
		}
		else if (action[i] == 'r') {
			bd[humans[i].x][humans[i].y + 1][Wall]++;
			if (humans[i].policy == Policy::Place) humans[i].policy = Policy::Normal;
		}
		else if (action[i] == 'U') {
			bd[humans[i].x][humans[i].y][Hito]--;
			humans[i].x--;
			bd[humans[i].x][humans[i].y][Hito]++;
			if (humans[i].dx == humans[i].x && humans[i].dy == humans[i].y) {
				humans[i].policy = Policy::Place;
			}
		}
		else if (action[i] == 'D') {
			bd[humans[i].x][humans[i].y][Hito]--;
			humans[i].x++;
			bd[humans[i].x][humans[i].y][Hito]++;
			if (humans[i].dx == humans[i].x && humans[i].dy == humans[i].y) {
				humans[i].policy = Policy::Place;
			}
		}
		else if (action[i] == 'L') {
			bd[humans[i].x][humans[i].y][Hito]--;
			humans[i].y--;
			bd[humans[i].x][humans[i].y][Hito]++;
			if (humans[i].dx == humans[i].x && humans[i].dy == humans[i].y) {
				humans[i].policy = Policy::Place;
			}
		}
		else if (action[i] == 'R') {
			bd[humans[i].x][humans[i].y][Hito]--;
			humans[i].y++;
			bd[humans[i].x][humans[i].y][Hito]++;
			if (humans[i].dx == humans[i].x && humans[i].dy == humans[i].y) {
				humans[i].policy = Policy::Place;
			}
		}
	}
	rep(i, num_pets) {
		rep(j, enemy_action[i].size()) {
			if (enemy_action[i][j] == '.') continue;
			else if (enemy_action[i][j] == 'U') {
				bd[pets[i].x][pets[i].y][pets[i].type]--;
				pets[i].x--;
				bd[pets[i].x][pets[i].y][pets[i].type]++;
			}
			else if (enemy_action[i][j] == 'D') {
				bd[pets[i].x][pets[i].y][pets[i].type]--;
				pets[i].x++;
				bd[pets[i].x][pets[i].y][pets[i].type]++;
			}
			else if (enemy_action[i][j] == 'L') {
				bd[pets[i].x][pets[i].y][pets[i].type]--;
				pets[i].y--;
				bd[pets[i].x][pets[i].y][pets[i].type]++;
			}
			else if (enemy_action[i][j] == 'R') {
				bd[pets[i].x][pets[i].y][pets[i].type]--;
				pets[i].y++;
				bd[pets[i].x][pets[i].y][pets[i].type]++;
			}
		}
	}
	time++; // 時間を進める
}

bool State::isAnimal(int x, int y) const {
	/* (x, y)に動物が存在するか */
	if (!isValid(x, y)) {
		cout << "error(isAnimal): x = " << x << ", y = " << y << endl; 
		return false;
	}
	for (int t : animal_list) if (bd[x][y][t] > 0) return true;
	return false;
}

bool State::canPlaceWall(int x, int y) const {
	/* (x, y)に壁を設置することができるか判定する */
	if (!isValid(x, y)) return false; // 範囲外
	if (bd[x][y][Hito] > 0) return false; // 設置先に人がいる
	if (isAnimal(x, y)) return false; // 設置先に動物がいる
	if (bd[x][y][Wall] > 0) return false; // 設置先にすでに壁がある
	// 設置先に隣接するマスに動物がいない
	if (isValid(x - 1, y) && isAnimal(x - 1, y)) return false;
	if (isValid(x + 1, y) && isAnimal(x + 1, y)) return false;
	if (isValid(x, y - 1) && isAnimal(x, y - 1)) return false;
	if (isValid(x, y + 1) && isAnimal(x, y + 1)) return false;
	return true;
}

bool State::canPlaceWall(int index, string direction) const {
	/* humans[index]がdirection方向に壁を設置することができるか判定する */
	if (index < 0 || num_humans <= index) {
		cout << "error(State::canPlaceWall): " << "index = " << index << endl;
		return false;
	}
	if (direction == "u") return canPlaceWall(humans[index].dx - 1, humans[index].dy);
	if (direction == "d") return canPlaceWall(humans[index].dx + 1, humans[index].dy);
	if (direction == "l") return canPlaceWall(humans[index].dx, humans[index].dy - 1);
	if (direction == "r") return canPlaceWall(humans[index].dx, humans[index].dy + 1);
	cout << "error(canPlaceWall): direction = " << direction << endl; 
	return false;
}

bool State::canMove(int x, int y) const {
	/* (x, y)に移動することができるか判定する */
	if (!isValid(x, y)) return false; // 範囲外に移動は不可
	if (bd[x][y][Wall] > 0) return false; // 設置先に壁がある
	return true;
}

bool State::canMove(int index, string direction) const {
	/* human[i]がdirection方向に移動可能か */
	if (index < 0 || num_humans <= index) {
		cout << "error(State::canMove): " << "index = " << index << endl;
		return false;
	}
	if (direction == "U") return canMove(humans[index].x - 1, humans[index].y);
	if (direction == "D") return canMove(humans[index].x + 1, humans[index].y);
	if (direction == "L") return canMove(humans[index].x, humans[index].y - 1);
	if (direction == "R") return canMove(humans[index].x, humans[index].y + 1);
	cout << "error(canMove): direction = " << direction << endl; 
	return false;
}

void State::out() const {
	rep(i, 30) {
		rep(j, 30) {
			if 		(bd[i][j][Wall] > 0)   cout << "#";
			else if (bd[i][j][Hito] > 0)   cout << "H";
			else if (this->isAnimal(i, j)) cout << "P";
			else						   cout << ".";
		}
		cout << endl;
	}
}



bool isValid(int x, int y) {
	// (x, y)が範囲内に属するか
	if (x < 0 || 30 <= x) return false;
	if (y < 0 || 30 <= y) return false;
	return true;
}



Action greedyAction(const State& state) {
	string ret = "";
	rep(i, state.num_humans) {
		/* 行動ポリシーをもとに次の行動を決定する */
		string d;
		switch (state.humans[i].policy) {
			case Policy::Normal:
				ret += ".";
				break;

			case Policy::Greedy:
				if 		(state.canPlaceWall(state.humans[i].x - 1, state.humans[i].y)) ret += "u";
				else if (state.canPlaceWall(state.humans[i].x + 1, state.humans[i].y)) ret += "d";
				else if (state.canPlaceWall(state.humans[i].x, state.humans[i].y - 1)) ret += "l";
				else if (state.canPlaceWall(state.humans[i].x, state.humans[i].y + 1)) ret += "r";
				else 									   							   ret += ".";
				break;

			case Policy::Move:
				d = state.route(i);
				if (state.canMove(i, d)) {
					ret += d;
				}
				else {
					ret += ".";
				}
				break;

			case Policy::Place:
				if (state.canPlaceWall(i, state.humans[i].direction)) {
					ret += state.humans[i].direction;
				}
				else {
					ret += ".";
				}
				break;

			default:
				ret += ".";
				break;
		}
	}
	return ret;
}

int main() {
	State state;
	string ans;
	while(!state.isDone()) {
		state.setPolicy();
		// cout << state.pattern.x << " " << state.pattern.y << endl;
		ans = greedyAction(state);
		cout << ans << endl; cout << flush;
		vector<string> enemy_action(state.num_pets);
		rep(j, state.num_pets) cin >> enemy_action[j];
		state.advance(ans, enemy_action);
	}
	return 0;
}