#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<int> h(3), w(3);
	rep(i, 3) cin >> h[i];
	rep(i, 3) cin >> w[i];
	vector<vector<int>> a(3, vector<int>(3));
	int ans = 0;
	for (a[0][0] = 1; a[0][0] <= 30; a[0][0]++) {
		for (a[0][1] = 1; a[0][1] <= 30; a[0][1]++) {
			for (a[1][0] = 1; a[1][0] <= 30; a[1][0]++) {
				for (a[1][1] = 1; a[1][1] <= 30; a[1][1]++) {
					a[0][2] = h[0] - a[0][0] - a[0][1];
					a[1][2] = h[1] - a[1][0] - a[1][1];
					a[2][0] = w[0] - a[0][0] - a[1][0];
					a[2][1] = w[1] - a[0][1] - a[1][1];
					a[2][2] = w[2] - a[0][2] - a[1][2];

					bool flg = true;
					rep(i, 3) rep(j, 3) if (a[i][j] <= 0) flg = false;
					if (h[2] != a[2][0] + a[2][1] + a[2][2]) flg = false;
					if (flg) ans++;
				}
			}
		}
	}
	cout << ans << endl;
}