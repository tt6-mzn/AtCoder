#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<int> j(7), d(7);
    rep(i, 7) cin >> j[i];
    rep(i, 7) cin >> d[i];
    int ans = 0;
    rep(i, 7) {
        ans += max(j[i], d[i]);
    }
    cout << ans << endl;
}