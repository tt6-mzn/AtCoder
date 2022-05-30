#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

int main() {
	long long n, m, k;
	cin >> n >> m >> k;
	vector<vector<mint>> dp(n, vector<mint>(m + 1));
	for (int j = 1; j <= m; j++) dp[0][j] = 1;

	for (int i = 1; i < n; i++) {
		// ss[j] = dp[i][1]からdp[i][j]までの総和
		vector<mint> ss(m + 1);
		ss[0] = 0;
		for (int j = 1; j <= m; j++) ss[j] = ss[j - 1] + dp[i - 1][j];

		for (int j = 1; j <= m; j++) {
			if (k == 0) {
				dp[i][j] = ss[m];
				continue;
			}
			dp[i][j] = ss[m] - (ss[min(m, j + (k - 1))] - ss[max(0LL, j - (k - 1) - 1)]);
		}
	}

	// for (int j = 1; j <= m; j++) {
	// 	rep(i, n) cout << dp[i][j].val() << " ";
	// 	cout << endl;
	// }

	mint ans = 0;
	for (int j = 1; j <= m; j++) ans += dp[n - 1][j];
	cout << ans.val() << endl;
	return 0;
}