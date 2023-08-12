#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    vector<int> t(q), x(q);
    vector<char> c(q);
    rep(i, q) cin >> t[i] >> x[i] >> c[i];

    int last_i = -1;
    rep(i, q) if (t[i] != 1) last_i = i;

    if (last_i == -1) {
        rep(i, q) {
            if (t[i] == 1) {
                s[x[i] - 1] = c[i];
            }
        }
        cout << s << endl;
        return 0;
    }

    vector<bool> isU;
    if (t[last_i] == 2) {
        isU.assign(n, false);
    }
    if (t[last_i] == 3) {
        isU.assign(n, true);
    }

    // cout << n << endl;
    // cout << s << endl;
    // cout << q << endl;
    // rep(i, q) {
    //     cout << t[i] << " " << x[i] << " " << c[i] << endl;
    // }
    // cout << last_i << " " << isU.size() << endl;
    // rep(_, isU.size()) { cout << isU[_] << " "; }
    // cout << endl;
    // return 0;

    rep(i, q) {
        if (t[i] == 1) {
            s[x[i] - 1] = c[i];
            if (i > last_i) {
                isU[x[i] - 1] = isupper(c[i]);
            }
        }
    }

    // rep(_, isU.size()) { cout << isU[_] << " "; }
    // cout << endl;

    rep(i, n) {
        if (isU[i]) {
            s[i] = toupper(s[i]);
        } else {
            s[i] = tolower(s[i]);
        }
    }
    cout << s << endl;
    return 0;
}