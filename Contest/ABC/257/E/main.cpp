#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	vector<long long> c(10);
	for (int i = 1; i < 10; i++) cin >> c[i];
	vector<vector<string>> dp(n + 1, vector<string>(10, "0"));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i - c[j] >= 0) {
				for (int k = 1; k <= 9; k++) {
					string tmp = dp[i - c[j]][k];
					tmp.append((to_string(j)));
					dp[i][j] = max(dp[i][j], tmp);
				}
			}
		}
	}

	// for (int j = 1; j <= 9; j++) {
	// 	rep(i, n + 1) cout << dp[i][j] << " ";
	// 	cout << endl;
	// }
	
	string ans = "";
	for (int i = 1; i <= 9; i++) {
		ans = max(ans, dp[n][i]);
	}
	int i = 0;
	while (ans[i] == '0') i++;
	while (i < ans.size()) {
		cout << ans[i];
		i++;
	}
	cout << endl;
	return 0;
}