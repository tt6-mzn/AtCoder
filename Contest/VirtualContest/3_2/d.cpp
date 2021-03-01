#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long mod = 998254353;

long long pow(long long a, long long n) {
    if (n == 1) {
        return a;
    }
    long long p = pow(a, n / 2);
    if (n % 2 == 0) {
        return (p * p) % mod;
    }
    else {
        return (((a * p) % mod) * p) % mod;
    }
}

int main() {
    long long n;
    cin >> n;
    vector<long long> d(n);
    rep(i, n) cin >> d[i];
    vector<long long> g(n, 0);
    rep(i, n) {
        g[d[i]]++;
    }
    rep(i, n - 1) {
        if (g[i] == 0 || g[i + 1] == 0) {
            cout << 0 << endl;
            return 0;
        }
        long long l, r;
        l = (g[i] * g[i + 1]) % mod;
        r = g[i + 1];
        // comb(l, r)を求める
        // i(1<=i<n)までのmodでの乗法逆元を事前計算
    }   
}


