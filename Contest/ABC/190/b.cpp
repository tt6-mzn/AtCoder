#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, s, d;
    cin >> n >> s >> d;
    bool flg = false;
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        if (x < s && y > d) {
            flg = true;
        }
    }
    if (flg) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
