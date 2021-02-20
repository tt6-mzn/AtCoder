#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> r(9, 0);
    rep(i, n) {
        int a;
        cin >> a;
        if (a >= 3200) {
            r[8]++;
        }
        else {
            r[a / 400]++;
        }
    }
    bool flg = true;
    int cnt = 0;
    rep(i, 8) {
        if (r[i] > 0) {
            flg = false;
            cnt++;
        }
    }
    if (flg) {
        cout << 1 << " " << r[8] << endl;
        return 0;
    }
    cout << cnt << " " << cnt + r[8] << endl;
}

