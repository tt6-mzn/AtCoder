#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool isNode(int y, int x, vector<string>& grid) {
	int n = grid.size();
	if (grid[y][x] == '#') return false;
	if (0 <= y - 1 && 0 <= x - 1) { // 上
		if (grid[y - 1][x] != '#' && grid[y][x - 1] != '#') return true;
	}
	if (y + 1 < n && 0 <= x - 1) { // 左
		if (grid[y + 1][x] != '#' && grid[y][x - 1] != '#') return true;
	}
	if (y + 1 < n && x + 1 < n) { // 下
		if (grid[y + 1][x] != '#' && grid[y][x + 1] != '#') return true;
	}
	if (0 <= y - 1 && x + 1 < n) {
		if (grid[y - 1][x] != '#' && grid[y][x + 1] != '#') return true;
	}
	return false;
}

bool isActive(int y, int x, vector<vector<bool>>& seen, vector<string>& grid) { // 周りに未訪問のマスがあるか?
	int n = grid.size();
	if (0 <= y - 1 && grid[y - 1][x] != '#' && seen[y - 1][x] == false) return true;
	if (0 <= x - 1 && grid[y][x - 1] != '#' && seen[y][x - 1] == false) return true;
	if (y + 1 < n && grid[y + 1][x] != '#' && seen[y + 1][x] == false) return true;
	if (x + 1 < n && grid[y][x + 1] != '#' && seen[y][x + 1] == false) return true;
	return false;
}

int see(int y, int x, vector<vector<bool>>& seen, vector<string>& grid) {
	int i, j, n = grid.size();
	int ret = 0;
	i = y;
	while (0 <= i && grid[i][x] != '#') {
		if (seen[i][x] == false) {
			seen[i][x] = true;
			ret++;
		}
		i--;
	}
	i = y;
	while (i < n && grid[i][x] != '#') {
		if (seen[i][x] == false) {
			seen[i][x] = true;
			ret++;
		}
		i++;
	}
	j = x;
	while (0 <= j && grid[y][j] != '#') {
		if (seen[y][j] == false) {
			seen[y][j] = true;
			ret++;
		}
		j--;
	}
	j = x;
	while (j < n && grid[y][j] != '#') {
		if (seen[y][j] == false) {
			seen[y][j] = true;
			ret++;
		}
		j++;
	}
	return ret;
}

int t_see(int y, int x, vector<vector<bool>>& seen, vector<string>& grid) {
	int i, j, n = grid.size();
	int ret = 0;
	i = y;
	while (0 <= i && grid[i][x] != '#') {
		if (seen[i][x] == false) {
			ret++;
		}
		i--;
	}
	i = y;
	while (i < n && grid[i][x] != '#') {
		if (seen[i][x] == false) {
			ret++;
		}
		i++;
	}
	j = x;
	while (0 <= j && grid[y][j] != '#') {
		if (seen[y][j] == false) {
			ret++;
		}
		j--;
	}
	j = x;
	while (j < n && grid[y][j] != '#') {
		if (seen[y][j] == false) {
			ret++;
		}
		j++;
	}
	return ret;
}

int walk(int y, int x, string& route, vector<vector<bool>>& seen, vector<string>& grid) {
	int ret = 0;
	rep(i, route.size()) {
		if (route[i] == 'U') y--;
		else if (route[i] == 'L') x--;
		else if (route[i] == 'D') y++;
		else x++;
		if (isNode(y, x, grid)) ret += see(y, x, seen, grid);
	}
	return ret;
}

string bfs(int sy, int sx, int gy, int gx, vector<vector<bool>>& seen_bfs, vector<string>& grid) {
	queue<tuple<int, int, int, string>> que;
	tuple<int, int, int, string> t;
	int y, x, cost, n = grid.size();
	string route;
	int min_cost = 1100100100;
	string ans_route;

	que.push({sy, sx, 0, ""});
	while (!que.empty()) {
		t = que.front(); que.pop();
		tie(y, x, cost, route) = t;
		if (y == gy && x == gx) {
			min_cost = cost;
			ans_route = route;
			break;
		}
		if (0 <= y - 1 && grid[y - 1][x] != '#' && seen_bfs[y - 1][x] == false) {
			que.push({y - 1, x, cost + grid[y - 1][x], route + "U"});
			seen_bfs[y - 1][x] = true;
		}
		if (0 <= x - 1 && grid[y][x - 1] != '#' && seen_bfs[y][x - 1] == false) {
			que.push({y, x - 1, cost + grid[y][x - 1], route + "L"});
			seen_bfs[y][x - 1] = true;
		}
		if (y + 1 < n && grid[y + 1][x] != '#' && seen_bfs[y + 1][x] == false) {
			que.push({y + 1, x, cost + grid[y + 1][x], route + "D"});
			seen_bfs[y + 1][x] = true;
		}
		if (x + 1 < n && grid[y][x + 1] != '#' && seen_bfs[y][x + 1] == false) {
			que.push({y, x + 1, cost + grid[y][x + 1], route + "R"});
			seen_bfs[y][x + 1] = true;
		}
	}
	return ans_route;
}

int main() {
	// input
	int n, sy, sx;
	cin >> n >> sy >> sx;
	vector<string> grid(n);
	rep(i, n) cin >> grid[i];

	// 前処理
	vector<vector<bool>> seen(n, vector<bool>(n, false)); // 監視済みのマス
	vector<pair<int, int>> nodes_pos;
	rep(i, n) rep(j, n) { // ノードをすべて列挙
		if (isNode(i, j, grid)) nodes_pos.push_back({i, j});
	}
	int m = nodes_pos.size(); // ノードの数
	int snode; // スタートのノード番号
	rep(i, m) {
		int y, x;
		tie(y, x) = nodes_pos[i];
		if (sy == y && sx == x) {
			snode = i;
		}
	}
	vector<vector<int>> G(m); // グラフ
	rep(i, m) {
		int y, x;
		tie(y, x) = nodes_pos[i];
		rep(j, m) {
			int ty, tx;
			tie(ty, tx) = nodes_pos[j];
			if (y == ty || x == tx) {
				G[i].push_back(j); // ノードi, jは隣り合う
			}
		}
	}

	// 貪欲解を生成
	int now = snode;
	string ans = "";
	while (1) {
		int max_d = -1;
		string max_route;
		int next_;
		for (int next : G[now]) {
			int now_y, now_x;
			int next_y, next_x;
			tie(now_y, now_x) = nodes_pos[now];
			tie(next_y, next_x) = nodes_pos[next];
			vector<vector<bool>> seen_bfs(n, vector<bool>(n, false));
			string s = bfs(now_y, now_x, next_y, next_x, seen_bfs, grid);
			int d = walk(now_y, now_x, s, seen, grid);
			if (max_d < d) {
				d = max_d;
				max_route = s;
				next_ = next;
			}
		}
		ans += max_route;
	}
}