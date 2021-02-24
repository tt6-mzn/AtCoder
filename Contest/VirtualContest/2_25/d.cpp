#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    vector<long long> x(n);
    rep(i, n) cin >> x[i];
    long long ans = 0;
    for (int i = 0; i < n - 1; i++) {
        ans += min(a * (x[i + 1] - x[i]), b);
    }
    cout << ans << endl;
}

