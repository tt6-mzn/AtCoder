#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<pair<int, int>> xy(3);
	rep(i, 3) {
		cin >> xy[i].first >> xy[i].second;
	}
	sort(xy.begin(), xy.end());
	int x, y;
	if (xy[0].first != xy[1].first) {
		x = xy[0].first;
		if (xy[0].second == xy[1].second) y = xy[2].second;
		else y = xy[1].second;
	}
	else {
		x = xy[2].first;
		if (xy[2].second == xy[0].second) y = xy[1].second;
		else y = xy[0].second;
	}
	cout << x << " " << y << endl;
	return 0;
}