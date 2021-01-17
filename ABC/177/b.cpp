#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    int ans = 1100, cnt = 0;
    rep(i, s.size() - t.size() + 1) {
        cnt = 0;
        rep(j, t.size()) {
            if(t.at(j) != s.at(i + j)) {
                cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << endl;
}