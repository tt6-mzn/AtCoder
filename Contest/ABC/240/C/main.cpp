#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<vector<bool>> dp(x + 1, vector<bool>(n, false));
	dp[0][0] = true;
	for (int i = 1; i < x + 1; i++) {
		for (int j = 1; j < n + 1; j++) {
			if (i - a[j - 1] >= 0 && dp[i - a[j - 1]][j - 1]) dp[i][j] = true;
			if (i - b[j - 1] >= 0 && dp[i - b[j - 1]][j - 1]) dp[i][j] = true;
		}
	}
	if (dp[x][n]) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}