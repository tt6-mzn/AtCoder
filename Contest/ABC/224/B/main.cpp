#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	rep(i, h) {
		rep(j, w) {
			cin >> a[i][j];
		}
	}
	rep(i2, h) {
		rep(i1, i2) {
			rep(j2, w) {
				rep(j1, j2) {
					if (a[i1][j1] + a[i2][j2] > a[i2][j1] + a[i1][j2]) {
						cout << "No" << endl;
						return 0;
					}
				}
			}
		}
	}
	cout << "Yes" << endl;
}