#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	vector<vector<mint>> dpy(k + 1, vector<mint>(n + 1, 0));
	vector<vector<mint>> dpx(k + 1, vector<mint>(n + 1, 1));
	rep(i, k + 1) {
		dpy[i][n] = 1;
		dpx[i][n] = 1;
	}
	// for (int i = 0; i <= k; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << "(" << dpy[i][j].val() << " " << dpx[i][j].val() << ")" << " ";
	// 	}
	// 	cout << endl;
	// }
	for (int i = 1; i <= k; i++) {
		// 残りi回
		rep(j, n) {
			// いまjにいる
			for (int d = 1; d <= m; d++) {
				int j_next;
				if (j + d > n) j_next = n - ((j + d) - n);
				else j_next = j + d;
				mint x1, y1, x2, y2;
				x1 = dpx[i][j];
				y1 = dpy[i][j];
				x2 = m * dpx[i - 1][j_next];
				y2 = dpy[i - 1][j_next];
				dpy[i][j] = x2 * y1 + x1 * y2;
				dpx[i][j] = x1 * x2;
			}
		}
	}
	// for (int i = 0; i <= k; i++) {
	// 	for (int j = 0; j <= n; j++) {
	// 		cout << "(" << dpy[i][j].val() << " " << dpx[i][j].val() << ")" << " ";
	// 	}
	// 	cout << endl;
	// }
	cout << (dpx[k][0].inv() * dpy[k][0]).val() << endl;
	return 0;
}