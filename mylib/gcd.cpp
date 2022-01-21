#include <iostream>
using namespace std;

/* ユークリッドの互除法を用いた最大公約数の計算
 * gcd(m, n)をm >= n > 0の時O(log n)で計算できる
 * lcm(m, n) = m * n / gcd(m, n)
*/
long long gcd(long long m, long long n) {
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main() {
    long long a, b;
    cin >> a >> b;
    cout << (a / gcd(a, b)) * b << endl;
}