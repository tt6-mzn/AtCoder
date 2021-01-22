#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<string> s(n);
    vector<int> t(n);
    rep(i, n) cin >> s[i] >> t[i];
    string x;
    cin >> x;

    bool flg = false;
    int ans = 0;
    rep(i, n) {
        if (flg == true) {
            ans += t[i];
        }
        else {
            if (s[i] == x) {
                flg = true;
            }
        }
    }

    cout << ans << endl;
}