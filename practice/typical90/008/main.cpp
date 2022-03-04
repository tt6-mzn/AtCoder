#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint1000000007;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	string t = "atcoder";
	int m = t.size();
	vector<vector<mint>> dp(m, vector<mint>(n + 1, 0));
	for (int j = n - 1; j >= 0; j--) {
		if (s[j] == t[m - 1]) dp[m - 1][j] = dp[m - 1][j + 1] + 1;
		else dp[m - 1][j] = dp[m - 1][j + 1];
	}
	for (int i = m - 2; i >= 0; i--) {
		for (int j = n - 1; j >= 0; j--) {
			if (s[j] == t[i]) dp[i][j] = dp[i][j + 1] + dp[i + 1][j + 1];
			else dp[i][j] = dp[i][j + 1];
		}
	}
	cout << dp[0][0].val() << endl;
	return 0;
}