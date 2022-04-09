#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    int r, s, p;
    cin >> r >> s >> p;
    string t;
    cin >> t;

    int ans = 0;
    rep(i, t.size()) {
        if (i >= k) {
            if (t[i] != t[i - k]) {
                if (t[i] == 'r') {
                    ans += p;
                }
                else if (t[i] == 's') {
                    ans += r;
                }
                else {
                    ans += s;
                }
            }
            else {
                t[i] = 'x';
            }
        }
        else {
            if (t[i] == 'r') {
                ans += p;
            }
            else if (t[i] == 's') {
                ans += r;
            }
            else {
                ans += s;
            }
        }
    }
    cout << ans << endl;
}