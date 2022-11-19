#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long H, W, n, h, w;
	cin >> H >> W >> n >> h >> w;

	vector<vector<long long>> a(H, vector<long long>(W));
	// vector<vector<long long>> a(n, vector<long long>(n)); <- ?????

	rep(i, H) rep(j, W) cin >> a[i][j];
	vector<vector<vector<long long>>> dp(H + 1, vector<vector<long long>>(W + 1, vector<long long>(301, 0)));
	for (long long i = 1; i < H + 1; i++) {
		for (long long j = 1; j < W + 1; j++) {
			for (long long k = 1; k <= 300; k++) {
				dp[i][j][k] = dp[i - 1][j][k] + dp[i][j - 1][k] - dp[i - 1][j - 1][k];
			}
			dp[i][j][a[i - 1][j - 1]]++;
		}
	}
	// for (long long k = 1; k <= 300; k++) cout << dp[2][1][k] << " ";
	// cout << endl;
	// rep(i, H + 1) {
	// 	rep(j, W + 1) {
	// 		long long test = 0;
	// 		for (long long k = 1; k <= 300; k++) if (dp[i][j][k] > 0) test++;
	// 		cout << test << " ";
	// 	}
	// 	cout << endl;
	// }
	// return 0;
	vector<vector<long long>> ans(H, vector<long long>(W, 0));
	rep(k, H - h + 1) rep(l, W - w + 1) {
		// [k, k + h), [l, l + w)
		vector<long long> tmp(301, 0);
		for (long long num = 1; num <= 300; num++) {
			tmp[num] = dp[k + h][l + w][num] - dp[k + h][l][num] - dp[k][l + w][num] + dp[k][l][num];
		}
		for (long long num = 1; num <= 300; num++) {
			tmp[num] = dp[H][W][num] - tmp[num];
		}
		long long cnt = 0;
		for (long long num = 1; num <= 300; num++) {
			if (tmp[num] > 0) cnt++;
		}
		ans[k][l] = cnt;
	}
	rep(k, H - h + 1) {
		cout << ans[k][0];
		for (long long l = 1; l < W - w + 1; l++) cout << " " << ans[k][l];
		cout << endl;
	}
	return 0;
}