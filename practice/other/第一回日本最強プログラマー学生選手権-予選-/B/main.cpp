#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long mod = 1000000007;
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	vector<long long> b(n, 0), c(n, 0);
	long long tmp = ((k * (k - 1)) / 2) % mod;
	rep(i, n) rep(j, n) {
		if (a[i] > a[j]) {
			if (i < j) b[i]++;
			c[i]++;
		}
	}
	// rep(_, b.size()) { cout << b[_] << " "; } cout << endl;
	// rep(_, c.size()) { cout << c[_] << " "; } cout << endl;
	long long ans = 0;
	for (int t : b) ans = (ans + ((k * t) % mod)) % mod;
	for (int t : c) ans = (ans + ((t * tmp) % mod)) % mod;
	cout << ans << endl;
	return 0;
}