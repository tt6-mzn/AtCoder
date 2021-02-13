#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    rep(i, 1 << 3) {
        int cnt = s[0] - '0';
        string ans = s.substr(0, 1);
        rep(j, 3) {
            if ((i >> j) & 1) {
                cnt += s[j + 1] - '0';
                ans += "+" + s.substr(j + 1, 1);
            }
            else {
                cnt -= s[j + 1] - '0';
                ans += "-" + s.substr(j + 1, 1);
            }
        }
        if (cnt == 7) {
            cout << ans << "=7" << endl;
            return 0;
        }
    }
}
