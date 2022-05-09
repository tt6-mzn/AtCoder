#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k;
	cin >> n >> k;
	string alp = "abcdefghijklmnopqrstuvwxyz";
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int ans = 0;
	for (int bit = 0; bit < (1 << n); bit++) {
		int cnt = 0;
		for (char c : alp) {
			int cnt_ = 0;
			rep(i, n) {
				if ((bit >> i) & 1) {
					if (s[i].find(c) != string::npos) cnt_++;
				}
			}
			if (cnt_ == k) cnt++;
		}
		ans = max(ans, cnt);
	}
	cout << ans << endl;
}