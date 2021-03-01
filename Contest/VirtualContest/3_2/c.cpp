#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s, t;
    cin >> s >> t;
    bool flg = true;
    string at = "atcoder";
    rep(i, s.size()) {
        if (s[i] == '@' && t[i] == '@') {
            continue;
        }
        else if (s[i] == '@') {
            if (at.find_first_of(t[i]) == string::npos) {
                flg = false;
            }
        }
        else if (t[i] == '@') {
            if (at.find_first_of(s[i]) == string::npos) {
                flg = false;
            }
        }
        else {
            if (s[i] != t[i]) {
                flg = false;
            }
        }
    }
    if (flg) {
        cout << "You can win" << endl;
    }
    else {
        cout << "You will lose" << endl;
    }
}

