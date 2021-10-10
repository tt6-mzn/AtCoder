#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const int DR[4] = {1, 0, -1, 0};
const int DC[4] = {0, 1, 0, -1};

class Vegetable {
public:
	int r, c, s, e, v;
	Vegetable(int r, int c, int s, int e, int v)
	: r(r), c(c), s(s), e(e), v(v) {
	}
};

class Action {
private:
	explicit Action(const vector<int> & vs_) : vs(vs_) {}
public:
	vector<int> vs;
	static Action pass() {
		return Action({-1});
	}
	static Action purchase(int r, int c) {
		return Action({r, c});
	}
	static Action move(int r1, int c1, int r2, int c2) {
		return Action({r1, c1, r2, c2});
	}
};

int N, M, T;
vector<vector<Vegetable>> veges_start;
vector<vector<Vegetable>> veges_end;

class Game {
public:
	vector<vector<bool>> has_machine; // その区画にマシンがあるか
	vector<vector<int>> vege_values; // その区画に生えている野菜の価値
	int num_machine; // マシンの数
	int next_price; // 次にマシンを購入するときの値段
	int money; // 現在のお金

	Game() : num_machine(0), next_price(1), money(1) {
		has_machine.assign(N, vector<bool>(N, false));
		vege_values.assign(N, vector<int>(N, 0));
	}

	void purchase(int r, int c) {
		assert(!has_machine[r][c]);
		assert(next_price <= money);
		has_machine[r][c] = true;
		money -= next_price;
		num_machine++;
		next_price = (num_machine + 1) * (num_machine + 1) * (num_machine + 1);
	}

	void move(int r1, int c1, int r2, int c2) {
		assert(has_machine[r1][c1]);
		has_machine[r1][c1] = false;
		assert(!has_machine[r2][c2]);
		has_machine[r2][c2] = true;
	}

	void simulate_before_action(int day) {
		/* 野菜の出現 */
		for (const Vegetable& vege : veges_start[day]) {
			vege_values[vege.r][vege.c] = vege.v;
		}
	}

	void simulate_after_action(int day, const Action& action) {
		/* actionを適用 */
		if (action.vs.size() == 2) {
			purchase(action.vs[0], action.vs[1]);
		} else if (action.vs.size() == 4) {
			move(action.vs[0], action.vs[1], action.vs[2], action.vs[3]);
		}
		/* 盤面の更新とお金の計算 */
		rep(i, N) {
			rep(j, N) {
				if (has_machine[i][j] && vege_values[i][j] > 0) {
					money += vege_values[i][j] * count_connected_machines(i, j);
					vege_values[i][j] = 0;
				}
			}
		}
		for (const Vegetable& vege : veges_end[day]) {
			vege_values[vege.r][vege.c] = 0;
		}
	}

	void simulate(int day, const Action& action) {
		/* actionを適用 */
		if (action.vs.size() == 2) {
			purchase(action.vs[0], action.vs[1]);
		} else if (action.vs.size() == 4) {
			move(action.vs[0], action.vs[1], action.vs[2], action.vs[3]);
		}
		/* 野菜の出現 */
		for (const Vegetable& vege : veges_start[day]) {
			vege_values[vege.r][vege.c] = vege.v;
		}
		/* 盤面の更新とお金の計算 */
		rep(i, N) {
			rep(j, N) {
				if (has_machine[i][j] && vege_values[i][j] > 0) {
					money += vege_values[i][j] * count_connected_machines(i, j);
					vege_values[i][j] = 0;
				}
			}
		}
		/* 野菜の消滅 */
		for (const Vegetable& vege : veges_end[day]) {
			vege_values[vege.r][vege.c] = 0;
		}
	}

    int count_connected_machines(int r, int c) {
        vector<pair<int, int>> queue = {{r, c}};
        vector<vector<int>> visited(N, vector<int>(N, 0));
        visited[r][c] = 1;
        int i = 0;
        while (i < queue.size()) {
            int cr = queue[i].first;
            int cc = queue[i].second;
            for (int dir = 0; dir < 4; dir++) {
                int nr = cr + DR[dir];
                int nc = cc + DC[dir];
                if (0 <= nr && nr < N && 0 <= nc && nc < N && has_machine[nr][nc] && !visited[nr][nc]) {
                    visited[nr][nc] = 1;
                    queue.push_back({nr, nc});
                }
            }
            i++;
        }
        return i;
    }

	Action select_next_action(int day) {
		/* マシンの数が5台未満で, 新たなマシンを購入可能な時 */
		if (num_machine < 5 && next_price <= money) {
			int max_v = 0;
			int max_r = -1, max_c = -1;
			rep(r, N) {
				rep(c, N) {
					if (!has_machine[r][c] && max_v < vege_values[r][c]) {
						max_v = vege_values[r][c];
						max_r = r;
						max_c = c;
					}
				}
			}
			if (max_v > 0) {
				return Action::purchase(max_r, max_c);
			}
		}
		/* マシンを購入しないとき */
		{
			int min_v = 1100100100, max_v = -1;
			int min_r = -1, min_c = -1;
			int max_r = -1, max_c = -1;
			rep(r, N) {
				rep(c, N) {
					if (has_machine[r][c] && vege_values[r][c] < min_v) {
						min_v = vege_values[r][c];
						min_r = r;
						min_c = c;
					}
					if (!has_machine[r][c] && vege_values[r][c] > max_v) {
						max_v = vege_values[r][c];
						max_r = r;
						max_c = c;
					}
				}
			}
			return Action::move(min_r, min_c, max_r, max_c);
		}
		return Action::pass();
	}
};

int main() {
	/* ---------- input ---------- */
	cin >> N >> M >> T;
	veges_start.resize(T);
	veges_end.resize(T);
	rep(i, M) {
		int r, c, s, e, v;
		cin >> r >> c >> s >> e >> v;
		Vegetable vege(r, c, s, e, v);
		veges_start[s].push_back(vege);
		veges_end[e].push_back(vege);
	}
	Game game;
	vector<Action> actions;
	rep(day, T) {
		game.simulate_before_action(day);
		Action action = game.select_next_action(day);
		actions.push_back(action);
		game.simulate_after_action(day, action);
	}
	for (const Action& action : actions) {
		rep(i, action.vs.size()) {
			cout << action.vs[i] << (i == action.vs.size() - 1 ? "\n" : " ");
		}
	}
}