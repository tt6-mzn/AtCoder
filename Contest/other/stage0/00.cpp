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

void see(int y, int x, vector<vector<bool>>& seen, vector<string>& grid) {
	int i, j, n = grid.size();
	i = y;
	while (0 <= i && grid[i][x] != '#') {
		seen[i][x] = true;
		i--;
	}
	i = y;
	while (i < n && grid[i][x] != '#') {
		seen[i][x] = true;
		i++;
	}
	j = x;
	while (0 <= j && grid[y][j] != '#') {
		seen[y][j] = true;
		j--;
	}
	j = x;
	while (j < n && grid[y][j] != '#') {
		seen[y][j] = true;
		j++;
	}
}

void walk(int y, int x, string& route, vector<vector<bool>>& seen, vector<string>& grid) {
	rep(i, route.size()) {
		if (route[i] == 'U') y--;
		else if (route[i] == 'L') x--;
		else if (route[i] == 'D') y++;
		else x++;
		if (isNode(y, x, grid)) see(y, x, seen, grid);
	}
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
	vector<vector<bool>> seen(n, vector<bool>(n, false));

	int ny = sy, nx = sx;
	string ans = "";
	rep(i, n) {
		rep(j, n) {
			if (isNode(i, j, grid) && isActive(i, j, seen, grid)) {
				vector<vector<bool>> seen_bfs(n, vector<bool>(n, false));
				string s = bfs(ny, nx, i, j, seen_bfs, grid);
				walk(ny, nx, s, seen, grid);
				ny = i;
				nx = j;
				ans += s;
			}
		}
	}
	vector<vector<bool>> seen_bfs(n, vector<bool>(n, false));
	string s = bfs(ny, nx, sy, sx, seen_bfs, grid);
	ny = sx;
	nx = sy;
	ans += s;
	cout << ans << endl;
}