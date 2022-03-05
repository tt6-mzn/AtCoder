#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

int main() {
	int n;
	cin >> n;
	vector<vector<mint>> dp(n, vector<mint>(10, 0));
	for (int j = 1; j <= 9; j++) dp[0][j] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= 9; j++) {
			if (j == 1) {
				dp[i][j] += dp[i - 1][j];
				dp[i][j] += dp[i - 1][j + 1];
			}
			else if (j == 9) {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] += dp[i - 1][j];
			}
			else {
				dp[i][j] += dp[i - 1][j - 1];
				dp[i][j] += dp[i - 1][j];
				dp[i][j] += dp[i - 1][j + 1];
			}
		}
	}
	mint ans = 0;
	for (int j = 1; j <= 9; j++) {
		ans += dp[n - 1][j];
	}
	cout << ans.val() << endl;
	return 0;
}