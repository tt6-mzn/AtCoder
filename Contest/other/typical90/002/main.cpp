#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<set<string>> dp(n + 1);
	if (n == 1) return 0;
	dp[2].insert("()");
	for (int i = 3; i <= n; i++) {
		for (int j = 1; j < i - 1; j++) {
			for (string s : dp[j]) {
				for (string t : dp[i - j]) {
					dp[i].insert(s + t);
				}
			}
		}
		for (string s : dp[i - 2]) {
			dp[i].insert("(" + s + ")");
		}
	}
	for (string ans : dp[n]) cout << ans << endl;
	return 0;
}