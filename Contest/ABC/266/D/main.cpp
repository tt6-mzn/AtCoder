#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n; cin >> n;
	vector<vector<long long>> a(100001, vector<long long>(5, 0));
	rep(i, n) {
		long long t, x, ai; cin >> t >> x >> ai;
		a[t][x] = ai;
	}
	vector<vector<long long>> dp(100001, vector<long long>(5, 0));
	rep(j, 5) dp[100000][j] = a[100000][j];
	for (int t = 99999; t >= 0; t--) {
		rep(j, 5) {
			dp[t][j] = dp[t + 1][j];
			if (j - 1 >= 0) dp[t][j] = max(dp[t][j], dp[t + 1][j - 1]);
			if (j + 1 < 5) dp[t][j] = max(dp[t][j], dp[t + 1][j + 1]);
			dp[t][j] += a[t][j];
		}
	}
	cout << dp[0][0] << endl;
	return 0;
}