#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<char> s(3), t(3);
	rep(i, 3) cin >> s[i];
	rep(i, 3) cin >> t[i];
	int s_inv = 0, t_inv = 0;
	// rep(_, s.size()) { cout << s[_] << " "; } cout << endl;
	// rep(_, t.size()) { cout << t[_] << " "; } cout << endl;
	rep(i, 3) rep(j, 3) {
		if (i < j) {
			if (s[i] > s[j]) s_inv++;
			if (t[i] > t[j]) t_inv++;
		}
	}
	if (abs(s_inv - t_inv) % 2 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}