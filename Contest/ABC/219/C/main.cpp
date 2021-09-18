#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string alp;
	cin >> alp;
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	map<char, char> dict, dict_inv;
	rep(i, 26) {
		dict[alp[i]] = (char)('a' + i);
	}
	rep(i, 26) {
		dict_inv[dict[(char)('a' + i)]] = (char)('a' + i);
	}

	vector<string> s_inv(n);
	rep(i, n) {
		rep(j, s[i].size()) {
			s_inv[i].push_back(dict[s[i][j]]);
		}
	}
	sort(s_inv.begin(), s_inv.end());
	vector<string> ans(n);
	rep(i, n) {
		rep(j, s_inv[i].size()) {
			ans[i].push_back(dict_inv[s_inv[i][j]]);
		}
	}
	rep(i, n) {
		cout << ans[i] << endl;
	}
}