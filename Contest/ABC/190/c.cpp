#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    rep(i, m) cin >> a[i] >> b[i];
    int k;
    cin >> k;
    vector<int> c(k), d(k);
    rep(i, k) cin >> c[i] >> d[i];

    int bit_max = 1 << k;
    int ans = 0;
    rep(i, bit_max) {
        vector<int> dish(n, 0);
        rep(j, k) {
            if ((i >> j) & 1) {
                dish[c[j] - 1]++;
            }
            else {
                dish[d[j] - 1]++;
            }
        }
        int cnt = 0;
        rep(j, m) {
            if (dish[a[j] - 1] > 0 && dish[b[j] - 1] > 0) {
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans << endl;
}

