#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m;
vector<string> s;
vector<vector<bool>> grid;

bool idou(int i, int j, int di, int dj, int& i_, int& j_) {
	bool ret = false;
	while (0 <= i && i < n && 0 <= j && j < m && s[i][j] == '.') {
		if (!grid[i][j]) {
			grid[i][j] = true;
			ret = true;
		}
		i += di; j += dj;
	}
	i_ = i - di;
	j_ = j - dj;
	return ret;
}

int main() {
	cin >> n >> m;
	s = vector<string>(n);
	rep(i, n) cin >> s[i];
	grid.assign(n, vector<bool>(m, false));

	queue<pair<int, int>> que;
	que.emplace(1, 1);

	while (!que.empty()) {
		int i, j, i_, j_;
		tie(i, j) = que.front(); que.pop();
		// 探索
		if (idou(i, j, -1,  0, i_, j_)) que.emplace(i_, j_);
		if (idou(i, j,  1,  0, i_, j_)) que.emplace(i_, j_);
		if (idou(i, j,  0, -1, i_, j_)) que.emplace(i_, j_);
		if (idou(i, j,  0,  1, i_, j_)) que.emplace(i_, j_);
	}

	// rep(_, grid.size()) { rep(__, grid[_].size()) { cout << grid[_][__] << " "; } cout << endl; }

	int ans = 0;
	rep(i, n) rep(j, m) {
		if (s[i][j] == '.' && grid[i][j]) ans++;
	}
	cout << ans << endl;
	
	return 0;
}