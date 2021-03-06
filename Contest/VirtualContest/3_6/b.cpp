#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n + 1), b(n);
    rep(i, n + 1) cin >> a[i];
    rep(i, n) cin >> b[i];
    long long ans = 0;
    rep(i, n) {
        ans += min(a[i], b[i]);
        b[i] -= min(a[i], b[i]);
        ans += min(a[i + 1], b[i]);
        a[i + 1] -= min(a[i + 1], b[i]);
    }
    cout << ans << endl;
}
