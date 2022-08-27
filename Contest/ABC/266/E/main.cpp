#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n; cin >> n;
	vector<vector<double>> dp(n + 1, vector<double>(7, 0));
	for (int j = 1; j <= 6; j++) dp[n][j] = j;
	for (int i = n - 1; i >= 1; i--) {
		double e = 0;
		for (int j = 1; j <= 6; j++) e += dp[i + 1][j];
		e /= 6;
		for (int j = 1; j <= 6; j++) {
			if (e >= j) dp[i][j] = e;
			else dp[i][j] = j;
		}
	}
	double e = 0;
	for (int j = 1; j <= 6; j++) e += dp[1][j];
	e /= 6;
	printf("%.10lf\n", e);
	return 0;
}