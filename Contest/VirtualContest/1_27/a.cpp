#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    int ans = 0;
    rep(i, n) {
        rep(j, i) {
            int dx, dy;
            dx = abs(x[i] - x[j]);
            dy = abs(y[i] - y[j]);
            if (dx >= dy) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}