#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/* エラトステネスの篩
 * isPrime[i] = true => i は素数
 * isPrime[i] = false => i は合成数
 * となるようなvectorを返す.
 * n: isPrime[n]まで求める
 * O(nloglogn)
*/
vector<bool> Eratostheness(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i * i < n + 1; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j < n + 1; j += i) isPrime[j] = false;
    }
    return isPrime;
}

/* エラトステネスの区間篩
 * b - a が十分に小さいとき [a, b] に属する整数kについて,
 * isPrime_AB[k - a] = true => k は素数
 * isPrime_AB[k - a] = false => k は合成数
 * となるような vector を返す.
 * O(√bloglogb + (b - a)loglogb)
*/
vector<bool> Eratostheness_interval(long long a, long long b) {
    long long sqrt_b = (long long)sqrt((double)b) + 1;
    vector<bool> isPrime(sqrt_b + 1, true);
    vector<bool> isPrime_AB(b - a + 1, true);
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i < sqrt_b + 1; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j < sqrt_b + 1; j += i) isPrime[j] = false;
        long long start = ((a + i - 1) / i) * i;
        if (start == i) start *= 2;
        for (long long j = start; j < b + 1; j += i) {
            isPrime_AB[j - a] = false;
        }
    }
    return isPrime_AB;
}