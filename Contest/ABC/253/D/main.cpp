#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/* ユークリッドの互除法を用いた最大公約数の計算
 * gcd(m, n)をm >= n > 0の時O(log n)で計算できる
 * lcm(m, n) = m * n / gcd(m, n)
*/
long long gcd(long long m, long long n) {
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main() {
	long long n, a, b;
	cin >> n >> a >> b;
	long long ans = n * (n + 1) / 2;
	ans -= (n / a) * (a + (n / a) * a) / 2;
	ans -= (n / b) * (b + (n / b) * b) / 2;
	long long lcm = (a * b) / gcd(a, b);
	ans += (n / lcm) * (lcm + (n / lcm) * lcm) / 2;
	cout << ans << endl;
	return 0;
}