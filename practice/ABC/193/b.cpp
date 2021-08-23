#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int ans = 1100100100;
    bool flg = false;
    rep(i, n) {
        int a, p, x;
        cin >> a >> p >> x;
        if (x - a > 0) {
            flg = true;
            ans = min(ans, p);
        }
    }
    if (flg) {
        cout << ans << endl;
    }
    else {
        cout << -1 << endl;
    }
}
