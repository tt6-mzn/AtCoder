#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	long long ans = 0;
	while (1) {
		// cout << a << " " << b << " " << c << endl;
		if ((a & 1) || (b & 1) || (c & 1)) {
			cout << ans << endl;
			return 0;
		}
		if (a == b && b == c) {
			cout << -1 << endl;
			return 0;
		}
		a /= 2; b /= 2; c /= 2;
		long long a_, b_, c_;
		a_ = a + b; b_ = a + c; c_ = b + c;
		a = a_; b = b_; c = c_;
		ans++;
	}
	return 0;
}