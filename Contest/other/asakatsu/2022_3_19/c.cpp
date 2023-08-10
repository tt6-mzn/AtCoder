#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    long long k;
    cin >> k;
    long long ans = 0;
    if (s.size() == 1) {
        cout << k / 2 << endl;
        return 0;
    }
    rep(i, s.size() - 1) {
        if (s[i] == s[i + 1]) {
            ans++;
            s[i + 1] = '*';
        }
    }
    ans *= k;
    if (s[0] == s[s.size() - 1]) {
        ans += k - 1;
    }
    cout << ans << endl;
}