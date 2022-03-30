#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint;

int main() {
	long long n, k;
	cin >> n >> k;
	mint::set_mod(n);
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	mint x = 0;
	long long ans = 0;
	map<int, bool> mp;
	while (!mp[x.val()]) {
		ans += a[x.val()];
		x += a[x.val()];
	}
	return 0;
}