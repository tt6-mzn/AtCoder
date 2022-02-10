#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> b;
	int now = 0;
	rep(i, n) {
		now += a[i];
		now %= 360;
		b.push_back(now);
	}
	sort(b.begin(), b.end());
	// rep(_, b.size()) { cout << b[_] << " "; } cout << endl;
	vector<int> c;
	for (int i = 1; i < b.size(); i++) {
		c.push_back(b[i] - b[i - 1]);
	}
	c.push_back(b[0]);
	c.push_back(360 - b[b.size() - 1]);
	// rep(_, c.size()) { cout << c[_] << " "; } cout << endl;
	int ans = -1;
	for (int t : c) ans = max(ans, t);
	cout << ans << endl;
	return 0;
}