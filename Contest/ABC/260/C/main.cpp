#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, x, y;
	cin >> n >> x >> y;
	vector<vector<long long>> dp(n + 1, vector<long long>(2)); // 0:青, 1:赤
	dp[1][0] = 1;
	dp[1][1] = 0;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][1] + y * dp[i - 1][0];
		dp[i][1] = dp[i - 1][1] + x * dp[i][0];
	}
	cout << dp[n][1] << endl;
	return 0;
}