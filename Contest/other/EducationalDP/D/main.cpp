#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, W; cin >> n >> W;
	vector<long long> w(n), v(n);
	rep(i, n) cin >> w[i] >> v[i];
	vector<vector<long long>> dp(n + 1, vector<long long>(W + 1, 0));
	// rep(i, n + 1) dp[i][0] = 0;
	// for (int j = 1; j < W + 1; j++) dp[0][w] = 0;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < W + 1; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - w[i - 1] >= 0) {
				dp[i][j] = max(dp[i][j], v[i - 1] + dp[i - 1][j - w[i - 1]]);
			}
		}
	}
	cout << dp[n][W] << endl;
	return 0;
}