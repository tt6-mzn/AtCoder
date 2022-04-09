#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


// 行動をintで表す
using Action = string;
using EnemyAction = vector<string>;


class Pet {
public:
	// 変数
	int x, y; // 座標
	int type; // ペットの種類
	// メンバ関数
	Pet(int x, int y, int type) : x(x), y(y), type(type) {}; // コンストラクタ
};

class Person {
public:
	// 変数
	int x, y; // 座標
	// メンバ関数
	Person(int x, int y) : x(x), y(y) {};
};

class State {
public:
	// 変数
	int time = 0; // ゲーム内時間
	int n; // ペットの数
	int m; // 人の数
	vector<vector<bool>> valid;
	vector<Pet> pets;
	vector<Person> people;
	// メンバ関数
	State(); // コンストラクタ
	bool isDone() const; // ゲームの終了判定
	void advance(const Action& action, const EnemyAction& enemy_action); // 指定したactionでゲームを1ターン進める
};

State::State() {
	cin >> n;
	rep(i, n) {
		int px, py, pt;
		cin >> px >> py >> pt;
		px--; py--;
		Pet t(px, py, pt);
		pets.push_back(t);
	}
	cin >> m;
	rep(i, m) {
		int hx, hy;
		cin >> hx >> hy;
		hx--; hy--;
		Person t(hx, hy);
		people.push_back(t);
	}
	valid.assign(30, vector<bool>(30, true));
	return;
}

bool State::isDone() const {
	/* ゲームの終了判定 */
	if (time >= 300) return true;
	return false;
}

void State::advance(const Action& action, const EnemyAction& enemy_action) {
	/* 指定したアクションでゲームを1ターン進める */
	rep(i, m) {
		if (action[i] == '.') continue;
		else if (action[i] == 'u') valid[people[i].x - 1][people[i].y] = false;
		else if (action[i] == 'd') valid[people[i].x + 1][people[i].y] = false;
		else if (action[i] == 'l') valid[people[i].x][people[i].y - 1] = false;
		else if (action[i] == 'r') valid[people[i].x][people[i].y + 1] = false;
		else if (action[i] == 'U') people[i].x--;
		else if (action[i] == 'D') people[i].x++;
		else if (action[i] == 'L') people[i].y--;
		else if (action[i] == 'R') people[i].x++;
	}
	rep(i, n) {
		rep(j, enemy_action[i].size()) {
			if (enemy_action[i][j] == '.') continue;
			else if (enemy_action[i][j] == 'U') pets[i].x--;
			else if (enemy_action[i][j] == 'D') pets[i].x++;
			else if (enemy_action[i][j] == 'L') pets[i].y--;
			else if (enemy_action[i][j] == 'R') pets[i].x++;
		}
	}
	time++; // 時間を進める
}

int main() {
	State s;
	string ans;
	rep(i, s.m) ans += ".";
	rep(i, 300) {
		cout << ans << endl; cout << flush;
		vector<string> enemy_action(s.n);
		rep(j, s.n) cin >> enemy_action[j];
		s.advance(ans, enemy_action);
	}
	cout << flush;
	return 0;
}