#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<long long> b(n);
    rep(i, n) cin >> a.at(i);
    long long ans = 0;
    long long mod = 1000000007;

    b.at(n - 1) = a.at(n - 1);
    for(int j = n - 2; 0 <= j; j--) {
        b.at(j) = a.at(j) + b.at(j + 1);
    }
    for(int i = 0; i < n - 1; i++) {
        ans += ((a.at(i)%mod) * (b.at(i+1)%mod)) % mod;
    }
    cout << ans % mod << endl;
}