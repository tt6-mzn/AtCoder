#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<int> e, v;
    int i = 0;
    while (i < s.size()) {
        int j = 0;
        while (i + j < s.size() && s[i] == s[i + j]) j++;
        if (s[i] == 'X') v.push_back(j);
        else e.push_back(j);
        i += j;
    }
    if (e.size() == 0) {
        cout << s.size() << endl;
        return 0;
    }
    if (v.size() == 0) {
        cout << min(k, (int)s.size()) << endl;
        return 0;
    }

    // 累積和
    vector<int> se(e.size() + 1), sv(v.size() + 1);
    se[0] = 0; sv[0] = 0;
    rep(i, e.size()) se[i + 1] = se[i] + e[i];
    rep(i, v.size()) sv[i + 1] = sv[i] + v[i];

    se.push_back(1100100100);
    long long ans = 0;
    rep(i, e.size()) { // 辺iを左端にとる
        int l = i, r = e.size() + 1; // いくつ左の辺まで選べるかを二部探索
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (se[mid] - se[i] > k) r = mid;
            else l = mid;
        }
        cout << i << " " << l << endl;
        cout << se[l] - se[i] + (sv[l + 1] - sv[i]) << endl;
    }
    return 0;
}