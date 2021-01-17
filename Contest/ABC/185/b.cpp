#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<vector<int>> a(h, vector<int>(w));
    rep(i, h) {
        rep(j, w) {
            cin >> a.at(i).at(j);
        }
    }

    int m = 1000;
    rep(i, h) {
        rep(j, w) {
            m = min(m, a.at(i).at(j));
        }
    }
    int ans = 0;
    rep(i, h) {
        rep(j, w) {
            ans += max(0, a.at(i).at(j) - m);
        }
    }
    cout << ans << endl;
}