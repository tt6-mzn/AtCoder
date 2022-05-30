#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> v(n);
	rep(i, n) v[i] = i + 1;
	map<int, int> mp;
	rep(i, n) mp[i + 1] = i;
	rep(i, q) {
		int x;
		cin >> x;
		int ind = mp[x];
		if (ind == n - 1) {
			swap(v[ind - 1], v[ind]);
			mp[v[ind]] = ind;
			mp[v[ind - 1]] = ind - 1;
			continue;
		}
		swap(v[ind], v[ind + 1]);
		mp[v[ind + 1]] = ind + 1;
		mp[v[ind]] = ind;
	}
	cout << v[0];
	for (int i = 1; i < n; i++) cout << " " << v[i];
	cout << endl;
	return 0;
}