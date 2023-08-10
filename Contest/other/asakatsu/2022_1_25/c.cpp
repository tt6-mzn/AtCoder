#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long gcd(long long m, long long n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) {
        int tmp;
        cin >> tmp;
        a[i] = abs(x - tmp);
    }
    int ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, a[i]);
    }
    cout << ans << endl;
}