#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<string> s(9);
	rep(i, 9) cin >> s[i];
	long long ans = 0;
	rep(i1, 9) rep(j1, 9) {
		for (int i2 = i1; i2 < 9; i2++) for (int j2 = j1 + 1; j2 < 9; j2++) {
			int i3, j3, i4, j4;
			i3 = i1 + (j2 - j1);
			j3 = j1 - (i2 - i1);
			i4 = i2 + (j2 - j1);
			j4 = j2 - (i2 - i1);
			if (i3 < 0 || 9 <= i3) continue;
			if (j3 < 0 || 9 <= j3) continue;
			if (i4 < 0 || 9 <= i4) continue;
			if (j4 < 0 || 9 <= j4) continue;
			if (s[i1][j1] == '#'
			 && s[i2][j2] == '#'
			 && s[i3][j3] == '#'
			 && s[i4][j4] == '#') {
				ans++;
			 }
		}
	}
	cout << ans << endl;
	return 0;
}