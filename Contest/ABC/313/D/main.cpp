#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> a0(n, -1), a1(n, -1);
    a0[0] = 0;
    a1[0] = 1;
    int t0, t_pre = -1, t;
    for (int skip = 0; skip < k + 1; skip++) {
        vector<int> x;
        rep(i, k + 1) {
            if (i == skip)
                continue;
            x.push_back(i + 1);
        }
        cout << "? " << x[0];
        for (int j = 1; j < k; j++)
            cout << " " << x[j];
        cout << endl;

        cin >> t;
        if (skip == 0) {
            t0 = t;
        } else if (t == t_pre) {
            a0[skip] = a0[skip - 1];
            a1[skip] = a1[skip - 1];
        } else {
            a0[skip] = 1 - a0[skip - 1];
            a1[skip] = 1 - a1[skip - 1];
        }
        t_pre = t;

        // cout << "t0: " << t0 << ", t_pre: " << t_pre << ",t: " << t << endl;
        // rep(_, a0.size()) { cout << a0[_] << " "; }
        // cout << endl;
        // rep(_, a1.size()) { cout << a1[_] << " "; }
        // cout << endl;
    }

    int s0 = 0;
    rep(i, k + 1) {
        s0 += a0[i];
    }
    vector<int> ans;
    if (s0 % 2 == t0)
        ans = a0;
    else
        ans = a1;

    // rep(_, ans.size()) { cout << ans[_] << " "; }
    // cout << endl;
    t0 = 0;
    for (int i = 1; i <= k; i++)
        t0 += ans[i];
    t0 = t0 % 2;

    for (int index = k + 1; index < n; index++) {
        cout << "? ";
        cout << 2;
        for (int i = 3; i <= k; i++) {
            cout << " " << i + 1;
        }
        cout << " " << index + 1;
        cout << endl;

        cin >> t;
        if (t == t0) {
            ans[index] = ans[k];
        } else {
            ans[index] = 1 - ans[k];
        }
    }

    cout << "!";
    rep(i, n) cout << " " << ans[i];
    cout << endl;

    return 0;
}