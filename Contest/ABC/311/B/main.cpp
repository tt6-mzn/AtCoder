#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, d;
	cin >> n >> d;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int ans = 0;

	rep(j, d + 1) rep(i, j) {
		bool flg = true;
		rep(k, n) {
			for (int dd = i; dd < j; dd++) {
				if (s[k][dd] == 'x') flg = false;
			}
		}
		if (flg) {
			ans = max(ans, j - i);
		}
	}
	cout << ans << endl;
	return 0;
}