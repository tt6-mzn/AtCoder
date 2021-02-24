#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long sx, sy, gx, gy, t, v;
    cin >> sx >> sy >> gx >> gy >> t >> v;
    long long n;
    cin >> n;
    rep(i, n) {
        long long x, y;
        cin >> x >> y;
        long long d1, d2;
        d1 = (x - sx) * (x - sx) + (y - sy) * (y - sy);
        d2 = (x - gx) * (x - gx) + (y - gy) * (y - gy);
        long long left, right;
        left = 4 * (t * v) * (t * v) * d2;
        right = (t * v) * (t * v) - d1 + d2;
        right = right * right;
        if (left <= right) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}
