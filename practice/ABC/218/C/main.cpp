#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;

int count_sharp(vector<string> &s) {
	int ret = 0;
	rep(i, s.size()) rep(j, s[0].size()) {
		if (s[i][j] == '#') ret++;
	}
	return ret;
}

pair<int, int> find_top_left(vector<string> &s) {
	int ri = 0, rj = 0;
	bool flg = false;
	rep(i, s.size()) {
		rep(j, s[0].size()) {
			if (s[i][j] == '#') {
				ri = i;
				flg = true;
				break;
			}
		}
		if (flg) break;
	}
	flg = false;
	rep(j, s[0].size()) {
		rep(i, s.size()) {
			if (s[i][j] == '#') {
				rj = j;
				flg = true;
				break;
			}
		}
		if (flg) break;
	}
	return {ri, rj};
}

vector<string> rotate(vector<string> &s) {
	vector<string> ret(n, string(n, '*'));
	rep(i, n) rep(j, n) {
		ret[i][j] = s[n - j - 1][i];
	}
	return ret;
}

int main() {
	cin >> n;
	vector<string> s(n), t(n);
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];

	// '#'の個数を数える
	if (count_sharp(s) != count_sharp(t)) {
		cout << "No" << endl;
		return 0;
	}
	rep(_, 4) {
		int si, sj, ti, tj;
		tie(si, sj) = find_top_left(s);
		tie(ti, tj) = find_top_left(t);
		bool flg = true;
		rep(i, n) rep(j, n) {
			if (n <= si + i) continue;
			if (n <= sj + j) continue;
			if (n <= ti + i) continue;
			if (n <= tj + j) continue;
			if (s[si + i][sj + j] != t[ti + i][tj + j]) flg = false;
		}
		if (flg) {
			cout << "Yes" << endl;
			return 0;
		}
		s = rotate(s);
	}
	cout << "No" << endl;
	return 0;
}