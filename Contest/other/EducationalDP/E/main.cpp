#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long inf = 1100100100100100100LL;

int main() {
	int n, W; cin >> n >> W;
	vector<long long> w(n), v(n);
	rep(i, n) cin >> w[i] >> v[i];
	long long v_sum = 0;
	rep(i, n) v_sum += v[i];
	vector<vector<long long>> dp(n + 1, vector<long long>(v_sum + 1, 0));
	rep(i, n + 1) dp[i][0] = 0;
	for (int j = 1; j < v_sum + 1; j++) dp[0][j] = inf;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < v_sum + 1; j++) {
			dp[i][j] = dp[i - 1][j];
			if (j - v[i - 1] >= 0) dp[i][j] = min(dp[i][j], dp[i - 1][j - v[i - 1]] + w[i - 1]);
		}
	}
	long long j = v_sum;
	while (j >= 0 && dp[n][j] > W) j--;
	cout << j << endl;
	return 0;
}