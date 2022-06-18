#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> lr(n);
	rep(i, n) cin >> lr[i].first >> lr[i].second;
	sort(lr.begin(), lr.end());
	vector<pair<int, int>> xy;
	int i = 0;
	while (i < n) {
		int x = lr[i].first;
		int y = lr[i].second;
		int j = 1;
		while (i + j < n && lr[i + j].first <= y) {
			y = max(y, lr[i + j].second);
			j++;
		}
		xy.emplace_back(x, y);
		i = i + j;
	}
	sort(xy.begin(), xy.end());
	rep(i, xy.size()) cout << xy[i].first << " " << xy[i].second << endl;
	return 0;
}