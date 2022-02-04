#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	int n = s.size();
	vector<vector<int>> dp(n + 1, vector<int>(3, -1));
	dp[0][1] = 0;
	dp[0][2] = 0;
	dp[1][1] = 1;
	dp[1][2] = 0;
	for (int i = 2; i < n + 1; i++) {
		// 最後が1文字
		if (s[i - 1] != s[i - 2]) dp[i][1] = max(dp[i][1], dp[i - 1][1] + 1);
		dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
		// 最後が2文字
		dp[i][2] = max(dp[i][2], dp[i - 2][1] + 1);
		// if (i - 4 >= 0 && s.substr(i - 2, 2) != s.substr(i - 4, 2)) dp[i][2] = max(dp[i][2], dp[i - 2][2] + 1);
	}
	
	// rep(_, dp.size()) { rep(__, dp[_].size()) { cout << dp[_][__] << " "; } cout << endl; }
	
	cout << max(dp[n][1], dp[n][2]) << endl;
	return 0;
}