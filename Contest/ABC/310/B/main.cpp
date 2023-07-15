#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> p(n), c(n);
	vector<vector<bool>> f(n, vector<bool>(m, false));
	rep(i, n) {
		cin >> p[i] >> c[i];
		rep(j, c[i]) {
			int fij; cin >> fij; fij--;
			f[i][fij] = true;
		}
	}

	rep(i, n) rep(j, n) {
		if (i == j) continue;
		if (p[i] < p[j]) continue;
		bool flg1 = true;
		bool flg2 = false;
		rep(k, m) {
			if (f[i][k] && !f[j][k]) flg1 = false;
			if (!f[i][k] && f[j][k]) flg2 = true;
		}
		if (flg1) {
			if (flg2) {
				cout << "Yes" << endl;
				return 0;
			}
			if (p[i] > p[j]) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}