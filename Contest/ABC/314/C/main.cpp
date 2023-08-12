#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<int> c(n);
    rep(i, n) cin >> c[i];
    map<int, char> mp;
    for (int i = 1; i <= m; i++)
        mp[i] = '*';

    rep(i, n) {
        char tmp = s[i];
        s[i] = mp[c[i]];
        mp[c[i]] = tmp;
    }
    rep(i, n) {
        if (s[i] == '*') {
            s[i] = mp[c[i]];
        }
    }
    cout << s << endl;
    return 0;
}