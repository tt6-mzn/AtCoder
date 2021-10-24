#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n), ab;
	rep(i, n) {
		cin >> a[i] >> b[i];
		ab.push_back(a[i]);
		ab.push_back(a[i] + b[i]);
	}
	// 座圧
	sort(ab.begin(), ab.end());
	ab.erase(unique(ab.begin(), ab.end()), ab.end());
	// 辞書化
	map<int, int> mp, mp_inv;
	rep(i, ab.size()) {
		mp[ab[i]] = i;
		mp_inv[i] = ab[i];
	}
	// imos
	vector<int> imos(ab.size(), 0);
	rep(i, n) {
		imos[mp[a[i]]]++;
		imos[mp[a[i] + b[i]]]--;
	}
	for (int i = 1; i < imos.size(); i++) imos[i] = imos[i - 1] + imos[i];
	// 答え
	vector<int> ans(n + 1, 0);
	rep(i, ab.size() - 1) {
		ans[imos[i]] += mp_inv[i + 1] - mp_inv[i];
	}
	// 出力
	cout << ans[1];
	for (int i = 2; i <= n; i++) {
		cout << " " << ans[i];
	}
	cout << endl;
}