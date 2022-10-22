#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long inf = 1100100100100100100LL;

int main() {
	int n, m; cin >> n >> m;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
	rep(i, n + 1) dp[i][0] = 0;
	for (int j = 1; j < m + 1; j++) dp[0][j] = -inf;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < m + 1; j++) {
			if (j > i) dp[i][j] = -inf;
			else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + a[i - 1] * j);
		}
	}
	cout << dp[n][m] << endl;
	return 0;
}