#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint1000000007;

int main() {
    int n;
    cin >> n;
    vector<mint> a(n);
    rep(i, n) {
        int ai;
        cin >> ai;
        a[i] = ai;
    }

    vector<mint> dp_plus(n, 0), dp_minus(n, 0);
    dp_plus[1] = a[1];
    for (int i = 2; i < n; i++) {
        dp_plus[i] = a[i] + dp_plus[i - 1];
        dp_plus[i] += a[i] + dp_minus[i - 1];
        if (i - 2 >= 0) {
            dp_minus[i] = -a[i] + a[i - 1] + dp_plus[i - 2];
        } else {
            dp_minus[i] = -a[i] + a[i - 1];
        }
    }
    mint ans = dp_plus[n - 1] + dp_minus[n - 1] + a[0];
    cout << ans.val() << endl;
    return 0;
}