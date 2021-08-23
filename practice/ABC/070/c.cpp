#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long gcd(long long a, long long b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    int n;
    cin >> n;
    vector<long long> t(n);
    rep(i, n) cin >> t[i];
    long long ans = t[0];
    for (int i = 1; i < n; i++) {
        ans = (ans / gcd(ans, t[i])) * t[i];
    }
    cout << ans << endl;
}