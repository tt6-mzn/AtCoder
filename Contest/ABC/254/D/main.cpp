#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (long long)(n); i++)

vector<long long> eratostheness(long long n) {
    vector<bool> isPrime(n + 1, true);
	vector<long long> minfactor(n + 1, -1);
    isPrime[0] = false; isPrime[1] = false;
	minfactor[0] = 0; minfactor[1] = 1;
    for (long long i = 2; i < n + 1; i++) {
        if (!isPrime[i]) continue;
		minfactor[i] = i;
        for (long long j = 2 * i; j < n + 1; j += i) {
			isPrime[j] = false;
			if (minfactor[j] == -1) minfactor[j] = i;
		}
    }
    return minfactor;
}

vector<pair<long long, long long>> factorize(long long n, vector<long long> &minfactor) {
	vector<pair<long long, long long>> res;
	while (n > 1) {
		long long p = minfactor[n];
		long long exp = 0;
		// n で割り切れる限り割る
		while (minfactor[n] == p) {
			n /= p;
			++exp;
		}
		res.emplace_back(p, exp);
	}
	return res;
}

vector<long long> divisors(long long n, vector<long long> &minfactor) {
	vector<long long> res({1});

	// n を素因数分解 (メンバ関数使用)
	auto pf = factorize(n, minfactor);
	rep(i, pf.size()) pf[i].second *= 2;

	// 約数列挙
	for (auto p : pf) {
		long long s = (long long)res.size();
		for (long long i = 0; i < s; ++i) {
			long long v = 1;
			for (long long j = 0; j < p.second; ++j) {
				v *= p.first;
				res.push_back(res[i] * v);
			}
		}
	}
	return res;
}

int main() {
	long long n;
	cin >> n;
	long long ans = 1;
	auto minfactor = eratostheness(n);
	for (long long k = 2; k <= n; k++) {
		long long m = 0;
		auto divisor = divisors(k, minfactor);
		for (auto d : divisor) {
			if (d <= n && k * k / d <= n) m++;
		}
		ans += m;
	}
	cout << ans << endl;
	return 0;
}