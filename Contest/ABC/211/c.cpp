#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	string chokudai = "chokudai";
	reverse(chokudai.begin(), chokudai.end());
	vector<long long> dp(s.size() + 1, 0);
	long long mod = 1000000007;
	int cnt = 0;
	for (char c : chokudai) {
		for (int i = s.size() - 1; i >= 0; i--) {
			if (cnt == 0 && s[i] == c) {
				dp[i] = dp[i + 1] + 1;
			}
			else if (s[i] == c) {
				dp[i] = (dp[i + 1] + dp[i]) % mod;
			}
			else {
				dp[i] = dp[i + 1];
			}
		}
		cnt++;
	}
	cout << dp[0] << endl;
}