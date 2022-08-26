#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s, t; cin >> s >> t;
	vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
	for (int i = 1; i <= s.size(); i++) {
		for (int j = 1; j <= t.size(); j++) {
			if (s[i - 1] == t[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	int i = s.size(), j = t.size();
	string ans = "";
	while (i >= 1 && j >= 1) {
		if (s[i - 1] == t[j - 1]) {
			ans += s[i - 1];
			i--; j--;
			continue;
		}
		if (dp[i][j] == dp[i - 1][j]) i--;
		else j--;
		// cout << i << " " << j << endl;
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
	return 0;
}