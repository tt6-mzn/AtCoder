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

	rep(j, w) {
		cout << a[0][j];
		for (int i = 1; i < h; i++) cout << " " << a[i][j];
		cout << endl;
	}
	return 0;
}