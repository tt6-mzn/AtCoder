#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w; cin >> h >> w;
	int q; cin >> q;
	vector<vector<bool>> grid(h, vector<bool>(w, false));
	dsu uf(h * w);
	rep(_, q) {
		int t; cin >> t;
		if (t == 1) {
			int r, c; cin >> r >> c;
			r--; c--;
			grid[r][c] = true;
			if (0 <= r - 1 && grid[r - 1][c]) uf.merge(r * w + c, (r - 1) * w + c);
			if (r + 1 < h && grid[r + 1][c]) uf.merge(r * w + c, (r + 1) * w + c);
			if (0 <= c - 1 && grid[r][c - 1]) uf.merge(r * w + c, r * w + (c - 1));
			if (c + 1 < w && grid[r][c + 1]) uf.merge(r * w + c, r * w + (c + 1));
		}
		if (t == 2) {
			int ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb;
			ra--; ca--; rb--; cb--;
			if (!(grid[ra][ca] && grid[rb][cb])) {
				cout << "No" << endl;
				continue;
			}
			if (uf.same(ra * w + ca, rb * w + cb)) {
				cout << "Yes" << endl;
			}
			else {
				cout << "No" << endl;
			}
		}
	}
	return 0;
}