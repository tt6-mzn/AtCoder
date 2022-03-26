#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<vector<bool>> dp(n, vector<bool>(2));
	dp[n - 1][0] = true; dp[n - 1][1] = true;
	for (int i = n - 2; i >= 0; i--) {
		if (dp[i + 1][0]) {
			if (abs(a[i] - a[i + 1]) <= k) dp[i][0] = true;
			if (abs(b[i] - a[i + 1]) <= k) dp[i][1] = true;
		}
		if (dp[i + 1][1]) {
			if (abs(a[i] - b[i + 1]) <= k) dp[i][0] = true;
			if (abs(b[i] - b[i + 1]) <= k) dp[i][1] = true;
		}
	}
	// rep(_, dp.size()) { rep(__, dp[_].size()) { cout << dp[_][__] << " "; } cout << endl; }
	if (dp[0][0] || dp[0][1]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}