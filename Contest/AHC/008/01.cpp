#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


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

vector<int> animal_list = {Ushi, Buta, Usagi, Inu, Neko};

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
	// メンバ関数
	Human(int x, int y) : x(x), y(y) {};
};

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
	// メンバ関数
	State(); // コンストラクタ
	bool isDone() const; // ゲームの終了判定
	void advance(const Action& action, const EnemyAction& enemy_action); // 指定したactionでゲームを1ターン進める
	bool isAnimal(int x, int y) const; // (x, y)に動物が存在するか
	bool canPlaceWall(int x, int y) const; // (x, y)に壁を設置可能か
	void out_bd() const;
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

void State::advance(const Action& action, const EnemyAction& enemy_action) {
	/* 指定したアクションでゲームを1ターン進める */
	rep(i, num_humans) {
		if (action[i] == '.') continue;
		else if (action[i] == 'u') bd[humans[i].x - 1][humans[i].y][Wall]++;
		else if (action[i] == 'd') bd[humans[i].x + 1][humans[i].y][Wall]++;
		else if (action[i] == 'l') bd[humans[i].x][humans[i].y - 1][Wall]++;
		else if (action[i] == 'r') bd[humans[i].x][humans[i].y + 1][Wall]++;
		else if (action[i] == 'U') {
			bd[humans[i].x][humans[i].y][Hito]--;
			humans[i].x--;
			bd[humans[i].x][humans[i].y][Hito]++;
		}
		else if (action[i] == 'D') {
			bd[humans[i].x][humans[i].y][Hito]--;
			humans[i].x++;
			bd[humans[i].x][humans[i].y][Hito]++;
		}
		else if (action[i] == 'L') {
			bd[humans[i].x][humans[i].y][Hito]--;
			humans[i].y--;
			bd[humans[i].x][humans[i].y][Hito]++;
		}
		else if (action[i] == 'R') {
			bd[humans[i].x][humans[i].y][Hito]--;
			humans[i].y++;
			bd[humans[i].x][humans[i].y][Hito]++;
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
	for (int t : animal_list) if (bd[x][y][t] > 0) return true;
	return false;
}

bool State::canPlaceWall(int x, int y) const {
	/* (x, y)に壁を設置することができるか判定する */
	if (!this->isValid(x, y)) return false; // 範囲外に壁は置けない
	if (bd[x][y][Hito] > 0) return false; // 設置先に人がいる
	if (this->isAnimal(x, y)) return false; // 設置先に動物がいる
	if (bd[x][y][Wall] > 0) return false; // 設置先にすでに壁がある
	// 設置先に隣接するマスに動物がいない
	if (this->isValid(x - 1, y) && this->isAnimal(x - 1, y)) return false;
	if (this->isValid(x + 1, y) && this->isAnimal(x + 1, y)) return false;
	if (this->isValid(x, y - 1) && this->isAnimal(x, y - 1)) return false;
	if (this->isValid(x, y + 1) && this->isAnimal(x, y + 1)) return false;
	return true;
}

void State::out_bd() const {
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



Action greedyAction(const State& state) {
	string ret = "";
	for (Human h : state.humans) {
		if 		(state.canPlaceWall(h.x - 1, h.y)) ret += "u";
		else if (state.canPlaceWall(h.x + 1, h.y)) ret += "d";
		else if (state.canPlaceWall(h.x, h.y - 1)) ret += "l";
		else if (state.canPlaceWall(h.x, h.y + 1)) ret += "r";
		else 									   ret += ".";
	}
	return ret;
}



int main() {
	State state;
	string ans;
	rep(i, 300) {
		// state.out_bd();
		ans = greedyAction(state);
		cout << ans << endl; cout << flush;
		vector<string> enemy_action(state.num_pets);
		rep(j, state.num_pets) cin >> enemy_action[j];
		state.advance(ans, enemy_action);
	}
	return 0;
}