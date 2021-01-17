#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s, t;
    cin >> s;
    cin >> t;
    int ans = 0;
    rep(i, s.size()) {
        if(s.at(i) != t.at(i)) {
            ans++;
        }
    }
    cout << ans << endl;
}