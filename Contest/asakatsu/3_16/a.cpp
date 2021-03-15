#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) {
        cin >> a[i] >> b[i];
    }
    int ans = 1000000;
    rep(i, n) {
        rep(j, n) {
            if (i == j) {
                ans = min(ans, a[i] + b[j]);
            }
            else {
                ans = min(ans, max(a[i], b[j]));
            }
        }
    }
    cout << ans << endl;
}