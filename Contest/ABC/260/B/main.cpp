#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	vector<pair<int, int>> xv(n), yv(n), zv(n);
	rep(i, n) {
		xv[i] = make_pair(a[i], -i);
		yv[i] = make_pair(b[i], -i);
		zv[i] = make_pair(a[i] + b[i], -i);
	}
	sort(xv.begin(), xv.end(), greater<pair<int, int>>());
	sort(yv.begin(), yv.end(), greater<pair<int, int>>());
	sort(zv.begin(), zv.end(), greater<pair<int, int>>());
	map<int, bool> mp;
	vector<int> ans;
	rep(i, x) {
		mp[-xv[i].second] = true;
		ans.push_back(-xv[i].second);
	}

	// rep(_, ans.size()) { cout << ans[_] << " "; } cout << endl;
	// return 0;
	
	int cnt = 0;
	int index = 0;
	while (cnt < y) {
		if (!mp[-yv[index].second]) {
			mp[-yv[index].second] = true;
			ans.push_back(-yv[index].second);
			cnt++;
		}
		index++;
	}
	cnt = 0;
	index = 0;
	while (cnt < z) {
		if (!mp[-zv[index].second]) {
			mp[-zv[index].second] = true;
			ans.push_back(-zv[index].second);
			cnt++;
		}
		index++;
	}
	sort(ans.begin(), ans.end());
	rep(i, ans.size()) cout << ans[i] + 1 << endl;
	return 0;
}