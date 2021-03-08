#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    rep(k, n) {
        rep(j, k) {
            rep(i, j) {
                if (s[i] != s[j] && s[i] != s[k] && s[j] != s[k]) {
                    if (j - i != k - j) {
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;
}