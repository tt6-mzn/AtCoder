#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> s(h);
	rep(i, h) cin >> s[i];
	int x, y, x_, y_;
	bool flg = false;
	rep(i, h) rep(j, w) {
		if (!flg && s[i][j] == 'o') {
			x = i;
			y = j;
			flg = true;
		}
		if (flg && s[i][j] == 'o') {
			x_ = i;
			y_ = j;
		}
	}
	// cout << x << " " << y << endl;
	// cout << x_ << " " << y_ << endl;
	cout << abs(x - x_) + abs(y - y_) << endl;
	return 0;
}