#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

int main() {
	mint a, b, c, d, e, f;
	long long a_, b_, c_, d_, e_, f_;
	cin >> a_ >> b_ >> c_ >> d_ >> e_ >> f_;
	a = a_;
	b = b_;
	c = c_;
	d = d_;
	e = e_;
	f = f_;
	mint ans = (a * b * c) - (d * e * f);
	cout << ans.val() << endl;
	return 0;
}