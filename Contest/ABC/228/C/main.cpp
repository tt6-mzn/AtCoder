#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> s_i(n);
    rep(i, n) {
        int p1, p2, p3;
        cin >> p1 >> p2 >> p3;
        s_i[i].first = p1 + p2 + p3;
        s_i[i].second = i;
    }
    sort(s_i.begin(), s_i.end(), greater<pair<int, int>>());
    vector<bool> ans(n, false);
    int b = s_i[k - 1].first;
    rep(i, n) {
        if (s_i[i].first + 300 >= b) {
            ans[s_i[i].second] = true;
        }
    }
    rep(i, n) {
        if (ans[i]) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}