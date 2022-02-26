#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int cnt;
	// 横
	rep(i, n) {
		rep(j, n - 6 + 1) {
			cnt = 0;
			rep(dj, 6) if (s[i][j + dj] == '#') cnt++;
			if (cnt >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	// 縦
	rep(i, n - 6 + 1) {
		rep(j, n) {
			cnt = 0;
			rep(di, 6) if (s[i + di][j] == '#') cnt++;
			if (cnt >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	// 斜め
	rep(i, n - 6 + 1) {
		rep(j, n - 6 + 1) {
			cnt = 0;
			rep(d, 6) if (s[i + d][j + d] == '#') cnt++;
			if (cnt >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	rep(i, n - 6 + 1) {
		for (int j = 5; j < n; j++) {
			cnt = 0;
			rep(d, 6) if (s[i + d][j - d] == '#') cnt++;
			if (cnt >= 4) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}