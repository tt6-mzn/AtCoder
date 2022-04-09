#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    if (s[0] != 'A') {
        cout << "WA" << endl;
        return 0;
    }
    int cnt = 0;
    int loc;
    for (int i = 2; i < s.size() - 1; i++) {
        if (s[i] == 'C') {
            cnt++;
            loc = i;
        }
    }
    if (cnt != 1) {
        cout << "WA" << endl;
        return 0;
    }
    rep(i, s.size()) {
        if (i != 0 && i != loc) {
            if (isupper(s[i])) {
                cout << "WA" << endl;
                return 0;
            }
        }
    }
    cout << "AC" << endl;
}