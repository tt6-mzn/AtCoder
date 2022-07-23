#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> x(n + 1, 0), y(n + 1, 0);
	rep(i, n) cin >> x[i + 1];
	rep(i, m) {
		long long c, yi;
		cin >> c >> yi;
		y[c] = yi;
	}

	vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));
	long long max_value = 0;
	long long next = -1;
	for (int i = 1; i <= n; i++) {
		next = -1;
		for (int j = 0; j <= i; j++) {
			// i回目でカウント値がjになるときの最大値
			if (j == 0) {
				// i回目で裏が出てカウント値が0になるとき
				dp[i][j] = max_value;
			}
			else {
				// i回目で表が出てカウント値がjになるとき
				dp[i][j] = x[i] + y[j] + dp[i - 1][j - 1];
			}
			next = max(next, dp[i][j]);
		}
		max_value = next;
	}
	cout << next << endl;
	return 0;
}