#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<pair<int, vector<int>>> ca(n);
    rep(i, n) {
        cin >> ca[i].first;
        rep(_, ca[i].first) {
            int ai;
            cin >> ai;
            ca[i].second.push_back(ai);
        }
    }
    int x;
    cin >> x;

    int c_min = 1100100100;
    for (auto &&[c, a] : ca) {
        if (find(a.begin(), a.end(), x) != a.end()) {
            c_min = min(c_min, c);
        }
    }

    vector<int> ans;
    rep(i, n) {
        int c = ca[i].first;
        auto a = ca[i].second;
        if (c == c_min && find(a.begin(), a.end(), x) != a.end()) {
            ans.push_back(i + 1);
        }
    }

    if (ans.size() == 0) {
        cout << 0 << endl;
        cout << endl;
        return 0;
    }

    cout << ans.size() << endl;
    cout << ans[0];
    for (int i = 1; i < ans.size(); i++) {
        cout << " " << ans[i];
    }
    cout << endl;
    return 0;
}