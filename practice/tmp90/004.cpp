#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<vector<int>> a(h, vector<int>(w));
	vector<vector<int>> b(h, vector<int>(w));
	rep(i, h) rep(j, w) cin >> a[i][j];
	vector<int> row(h, 0), column(w, 0);
	rep(i, h) rep(j, w) row[i] += a[i][j];
	rep(i, w) rep(j, h) column[i] += a[j][i];
	rep(i, h) rep(j, w) {
		b[i][j] = row[i] + column[j] - a[i][j];
	}
	rep(i, h) {
		cout << b[i][0];
		for (int j = 1; j < w; j++) {
			cout << " " << b[i][j];
		}
		cout << endl;
	}
}