#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n), sa(n);
	rep(i, n) { cin >> a[i]; sa[i] = a[i]; }
	sort(sa.begin(), sa.end());
	map<int, multiset<int>> mp;
	rep(i, n) mp[a[i]].insert(i % k);
	rep(i, n) {
		auto it = mp[sa[i]].find(i % k);
		if (it == mp[sa[i]].end()) {
			cout << "No" << endl;
			return 0;
		}
		mp[sa[i]].erase(it);
	}
	cout << "Yes" << endl;
	return 0;
}