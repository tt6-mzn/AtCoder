#include <bits/stdc++.h>
using namespace std;

/* 自然数nをO(√n)で素因数分解する関数
 * [素因数, 指数]のpairのvectorを返す。
 */
vector<pair<long long, long long>> factorize(long long n) {
	long long p = 2;
	vector<pair<long long, long long>> ret;
	while (p * p <= n) {
		long long e = 0;
		while (n % p == 0) { e++; n /= p; }
		if (e > 0) ret.emplace_back(p, e);
		p++;
	}
	if (n > 1) ret.emplace_back(n, 1);
	return ret;
}

int main() {
	long long a;
	cin >> a;
	if (a == 1) {
		cout << 1 << endl;
		return 0;
	}
	const auto& prime = factorize(a);
	long long ans = 1;
	for (auto [p, e] : prime) {
		if (e & 1) ans *= p;
	}
	cout << ans << endl;
}