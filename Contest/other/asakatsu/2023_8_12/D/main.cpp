#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, bool>>> axy(n);
    rep(i, n) {
        int ai;
        cin >> ai;
        rep(_, ai) {
            int x, y;
            cin >> x >> y;
            x--;
            axy[ai].emplace_back(x, y);
        }
    }

    int ans = 0;
    for (int b = 0; b < (1 << n); b++) {
        vector<bool> honest(n);
        rep(i, n) honest[i] = 1 & (b >> i);

        bool flg = true;
        rep(i, n) {
            for (auto [x, y] : axy[i]) {
                if (honest[x] != (y != honest[i]))
                    flg = false;
            }
        }

        rep(_, honest.size()) { cout << honest[_] << " "; }
        cout << endl;
        cout << flg << endl;

        if (flg)
            ans = max(ans, accumulate(honest.begin(), honest.end(), 0));
    }
    cout << ans << endl;
    return 0;
}