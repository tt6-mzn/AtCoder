/*
ユークリッドの互除法を用いた最大公約数の計算
gcd(m, n)をm >= n > 0の時O(log n)で計算できる
(long long, long long) -> (long long)
*/

#include <iostream>
using namespace std;

long long gcd(long long m, long long n) {
    if (n == 0) return m;
    return gcd(n, m % n);
}

int main() {
    cout << gcd(51, 15) << endl;
    cout << gcd(15, 51) << endl;
    cout << 15 % 51 << endl; 
}