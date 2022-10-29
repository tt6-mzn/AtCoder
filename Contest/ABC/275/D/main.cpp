#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

map<long long, bool> memo;
map<long long, long long> f;

long long solve(long long n) {
	long long ret1, ret2;
	if (n == 0) return 1LL;
	if (memo[n]) return f[n];
	ret1 = solve(n / 2);
	ret2 = solve(n / 3);
	memo[n] = true;
	f[n] = ret1 + ret2;
	return ret1 + ret2;
}

int main() {
	long long n;
	cin >> n;
	cout << solve(n) << endl;
	return 0;
}