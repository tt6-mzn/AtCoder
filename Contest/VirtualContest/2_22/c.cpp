#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m, l;
    cin >> n >> m >> l;
    int p, q, r;
    cin >> p >> q >> r;
    int ans = 0;
    ans = max(ans, (n / p) * (m / q) * (l / r));
    ans = max(ans, (n / q) * (m / r) * (l / p));
    ans = max(ans, (n / r) * (m / p) * (l / q));
    ans = max(ans, (n / q) * (m / p) * (l / r));
    ans = max(ans, (n / p) * (m / r) * (l / q));
    ans = max(ans, (n / r) * (m / q) * (l / p));
    cout << ans << endl;
}