#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    rep(i, n) cin >> a[i];
    rep(i, m) cin >> b[i];

    rep(i, n - m + 1) {
        rep(j, n - m + 1) {
            bool flg = true;
            rep(k, m) {
                if (a[i + k].substr(j, m) != b[k]) {
                    flg = false;
                }
            }
            if (flg) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;
}