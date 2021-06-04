#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, k;
    cin >> n >> k;
    vector<vector<long long>> a(n, vector<long long>(n));
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }
    long long ans = 1100100100;
    vector<long long> t(k * k);
    rep(i, n - k + 1) {
        rep(j, n - k + 1) {
            int cnt = 0;
            for (int u = i; u < i + k; u++) {
                for (int v = j; v < j + k; v++) {
                    t[cnt] = a[u][v];
                    cnt++;
                }
            }
            sort(t.begin(), t.end(), greater<long long>());
            ans = min(ans, t[(k * k) / 2]);
        }
    }
    cout << ans << endl;
}