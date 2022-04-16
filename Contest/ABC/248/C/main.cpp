#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<mint>> dp(n + 1, vector<mint>(k + 1, 0));
	dp[0][0] = 1;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < k + 1; j++) {
			for (int ai = 1; ai <= m; ai++) {
				if (j - ai >= 0) dp[i][j] += dp[i - 1][j - ai];
			}
		}
	}

	// rep(i, n + 1) {
	// 	rep(j, k + 1) {
	// 		cout << dp[i][j].val() << " ";
	// 	}
	// 	cout << endl;
	// }
	
	mint ans = 0;
	rep(i, k + 1) ans += dp[n][i];
	cout << ans.val() << endl;
	return 0;
}