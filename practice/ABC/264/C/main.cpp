#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h1, w1;
	cin >> h1 >> w1;
	vector<vector<int>> a(h1, vector<int>(w1));
	rep(i, h1) rep(j, w1) cin >> a[i][j];

	int h2, w2;
	cin >> h2 >> w2;
	vector<vector<int>> b(h2, vector<int>(w2));
	rep(i, h2) rep(j, w2) cin >> b[i][j];

	if (h1 < h2 || w1 < w2) {
		cout << "No" << endl;
		return 0;
	}

	rep(bh1, 1 << h1) rep(bw1, 1 << w1) {
		vector<int> h1ind, w1ind;
		rep(i, h1) if ((bh1 >> i) & 1) h1ind.push_back(i);
		rep(j, w1) if ((bw1 >> j) & 1) w1ind.push_back(j); 
		if (h1ind.size() != h2) continue;
		if (w1ind.size() != w2) continue;
		bool flg = true;
		rep(i, h2) rep(j, w2) {
			if (a[h1ind[i]][w1ind[j]] != b[i][j]) flg = false;
		}
		if (flg) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}