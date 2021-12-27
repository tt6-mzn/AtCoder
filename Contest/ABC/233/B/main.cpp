#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int l, r;
    cin >> l >> r;
    string s;
    cin >> s;
    string sub = s.substr(l - 1, r - l + 1);
    reverse(sub.begin(), sub.end());
    cout << s.substr(0, l - 1) << sub << s.substr(r, s.size() - r) << endl;
    // cout << s.substr(0, l - 1) << endl;
    // cout << sub << endl;
    // cout << s.substr(r, s.size() - r) << endl;
    return 0;
}