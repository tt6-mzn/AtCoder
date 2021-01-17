#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 10^n - 9^n - 9^n + 8^n
int main() {
    int n;
    cin >> n;
    long long pow10=1, pow9=1, pow8=1;
    long long mod = 1000000007;
    long long ans;
    rep(i, n) {
        pow10 = (pow10 * 10) % mod;
        pow9 = (pow9 * 9) % mod;
        pow8 = (pow8 * 8) % mod;
    }
    ans = (pow10 - pow9) % mod;
    ans = (ans - pow9) % mod;
    ans = (ans + pow8) % mod;
    ans = (ans + mod) % mod;
    cout << ans << endl;
}