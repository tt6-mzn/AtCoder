#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s, t;
    cin >> s >> t;
    vector<int> ans(s.size());
    rep(i, s.size()) {
        if (s[i] <= t[i]) {
            ans[i] = t[i] - s[i];
        }
        else {
            ans[i] = (26 - (s[i] - 'a')) + (t[i] - 'a');
        }
    }
    for (int i = 1; i < s.size(); i++) {
        if (ans[0] != ans[i]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}