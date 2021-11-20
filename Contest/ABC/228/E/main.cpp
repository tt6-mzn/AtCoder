#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, k, m;
    cin >> n >> k >> m;
    modint::set_mod(998244353 - 1);
    modint t = k;
    t = t.pow(n);
    if (m % 998244353 == 0) {
        cout << 0 << endl;
        return 0;
    }
    modint998244353 ans = m;
    ans = ans.pow(t.val());
    cout << ans.val() << endl;
}