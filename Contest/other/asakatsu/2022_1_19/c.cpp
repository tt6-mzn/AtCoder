#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x1, y1, r;
    cin >> x1 >> y1 >> r;
    int x2, y2, x3, y3;
    cin >> x2 >> y2 >> x3 >> y3;
    bool flg = true;
    if ((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1) <= r) {
        if ((x3 - x1) * (x3 - x1) + (y2 - y1) * (y2 - y1) <= r) {
            if ((x2 - x1) * (x2 - x1) + (y3 - y1) * (y3 - y1) <= r) {
                if ((x3 - x1) * (x3 - x1) + (y3 - y1) * (y3 - y1) <= r) {
                    cout << "NO" << endl;
                    flg = false;
                }
            }
        }
    }
    if (flg) {
        cout << "YES" << endl;
    }
    flg = true;
    if (y2 >= y1 + r && y3 <= y1 - r) {
        if (x2 <= x1 - r && x3 >= x1 + r) {
            cout << "NO" << endl;
            flg = false;
        }
    }
    if (flg) {
        cout << "YES" << endl;
    }
}