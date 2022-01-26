#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	int ans = 0;
	for (char c : s) ans += c - '0';
	rep(i, s.size()) {
		int tmp = 0;
		if (s[i] == '0') continue;
		// 文字s[i]をs[i] - 1とし、それ以下を9で埋める場合
		rep(j, s.size()) {
			if (j < i) tmp += s[j] - '0';
			if (j == i) tmp += s[j] - '0' - 1;
			if (j > i) tmp += 9;
		}
		ans = max(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}