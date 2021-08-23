#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x, n;
    cin >> x >> n;
    vector<int> p(n);
    rep(i, n) cin >> p.at(i);
    int d = 0;
    while(true) {
        bool flg = true;
        rep(i, n) {
            if (p.at(i) == x - d) {
                flg = false;
            }
        }
        if (flg) {
            cout << x - d << endl;
            return 0;
        }
        flg = true;
        rep(i, n) {
            if (p.at(i) == x + d) {
                flg = false;
            }
        }
        if (flg) {
            cout << x + d << endl;
            return 0;
        }
        d++;
    }
}