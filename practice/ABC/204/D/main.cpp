#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	int s = 0;
	rep(i, n) s += t[i];
	// dp[i][j] = i未満の仕事から選んで総和をjにできるか
	vector<vector<bool>> dp(n + 1, vector<bool>(s + 1, false));
	rep(i, n + 1) dp[i][0] = true;
	for (int i = 1; i < n + 1; i++) {
		for (int j = 1; j < s + 1; j++) {
			if (dp[i - 1][j]) dp[i][j] = true;
			if (j - t[i - 1] >= 0 && dp[i - 1][j - t[i - 1]]) dp[i][j] = true;
		}
	}
	int j = (s + 1) / 2;
	while (!dp[n][j]) j++;
	cout << j << endl;
	return 0;
}