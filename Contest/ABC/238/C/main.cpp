#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

modint998244353 inv2 = 2;

long long F(long long a, long long b) {
	modint998244353 ret, ret1, ret2;
	if ((a + b) % 2 == 0) ret1 = (a + b) / 2;
	else ret1 = a + b;
	if ((b - a + 1) % 2 == 0) ret1 *= (b - a + 1) / 2;
	else ret1 *= b - a + 1;

	ret2 = a - 1;
	ret2 *= b - a + 1;
	ret = ret1 - ret2;
	return ret.val();
}

int main() {
	long long n;
	cin >> n;
	// inv2 = inv2.inv();
	long long a = 1;
	modint998244353 ans = 0;
	while (a * 10 - 1 < n) {
		ans += F(a, a * 10 - 1);
		// cout << ans.val() << endl;
		// return 0;
		a *= 10;
	}
	ans += F(a, n);
	cout << ans.val() << endl;
	return 0;
}