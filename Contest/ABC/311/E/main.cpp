#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long h, w, n;
	cin >> h >> w >> n;
	vector<vector<bool>> grid(h, vector<bool>(w, true));
	rep(_, n) {
		long long a, b;
		cin >> a >> b;
		a--; b--;
		grid[a][b] = false;
	}

	// rep(_, grid.size()) { rep(__, grid[_].size()) { cout << grid[_][__] << " "; } cout << endl; }

	vector<vector<bool>> hi(h, vector<bool>(w));
	vector<vector<bool>> ue(h, vector<bool>(w));

	rep(i, h) hi[i][0] = grid[i][0];
	// rep(j, w) hi[0][j] = grid[0][j];
	// rep(i, h) ue[i][0] = grid[i][0];
	rep(j, w) ue[0][j] = grid[0][j];

	for (int i = 0; i < h; i++) {
		for (int j = 1; j < w; j++) {
			hi[i][j] = grid[i][j] && hi[i][j - 1];
		}
	}
	for (int i = 1; i < h; i++) {
		for (int j = 0; j < w; j++) {
			ue[i][j] = grid[i][j] && ue[i - 1][j];
		}
	}

	// rep(_, hi.size()) { rep(__, hi[_].size()) { cout << hi[_][__] << " "; } cout << endl; }
	// rep(_, ue.size()) { rep(__, ue[_].size()) { cout << ue[_][__] << " "; } cout << endl; }

	vector<vector<long long>> dp(h, vector<long long>(w, 0));
	rep(i, h) dp[i][0] = grid[i][0];
	rep(j, w) dp[0][j] = grid[0][j];
	for (int i = 1; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if (grid[i][j]) {
				dp[i][j] = 1;
				if (hi[i][j] && ue[i][j]) dp[i][j] += dp[i - 1][j - 1];
			}
			else {
				dp[i][j] = 0;
			}
		}
	}
	long long ans = 0;
	rep(i, h) rep(j, w) ans += dp[i][j];
	cout << ans << endl;
	
	return 0;
}