#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n), cmp_a(n);
	rep(i, n) cin >> a[i];

	rep(i, n) cmp_a[i] = a[i]; // 座圧用配列
	sort(cmp_a.begin(), cmp_a.end());
	cmp_a.erase(unique(cmp_a.begin(), cmp_a.end()), cmp_a.end()); // 座圧
	map<int, int> mp;
	rep(i, cmp_a.size()) mp[cmp_a[i]] = i + 1; // map作成

	vector<vector<int>> memo(cmp_a.size());
	rep(i, n) memo[mp[a[i]] - 1].push_back(i);

	rep(i, q) {
		int x, k;
		cin >> x >> k;
		if (mp[x] == 0) {
			cout << -1 << endl;
			continue;
		}
		if (k <= memo[mp[x] - 1].size()) {
			cout << memo[mp[x] - 1][k - 1] + 1 << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	return 0;
}