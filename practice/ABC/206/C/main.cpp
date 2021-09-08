#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	map<long long, long long> dict;
	rep(i, n) dict[a[i]]++;
	long long ans = 0;
	for (const auto &item : dict) {
		ans += item.second * (n - item.second);
	}
	cout << ans / 2 << endl;
}