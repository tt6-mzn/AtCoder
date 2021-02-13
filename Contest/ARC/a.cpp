#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long t;
    cin >> t;
    rep(i, t) {
        long long l, r;
        cin >> l >> r;
        if (r - 2 * l + 1 > 0) {
            cout << (r - 2 * l + 2) * (r - 2 * l + 1) / 2 << endl;
        }
        else {
            cout << 0 << endl;
        }
    }
}