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
	vector<vector<int>> vs(n + 1);
	rep(i, n) vs[a[i]].push_back(i);
	int q;
	cin >> q;
	rep(i, q) {
		int l, r, x;
		cin >> l >> r >> x;
		l--; r--;
		auto left = lower_bound(vs[x].begin(), vs[x].end(), l);
		auto right = upper_bound(vs[x].begin(), vs[x].end(), r);
		cout << (int)(right - left) << endl;
	}
	return 0;
}