#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<bool> rate(8, false);
    int cnt = 0;
    rep(i, n) {
        if (3200 <= a[i]) {
            cnt++;
        }
        else {
            rate[a[i] / 400] = true;
        }
    }
    int ans = 0;
    rep(i, 8) {
        if (rate[i] == true) {
            ans++;
        }
    }
    if (ans == 0) {
        cout << 1 << " " << ans + cnt << endl;
    }
    else {
        cout << ans << " " << ans + cnt << endl;
    }
}