#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(9, 0);
    rep(i, n) {
        int r;
        cin >> r;
        if (r / 400 <= 7) {
            a[r / 400]++;
        }
        else {
            a[8]++;
        }
    }
    int ans = 0;
    rep(i, 8) {
        if (a[i] > 0) {
            ans++;
        }
    }
    if (ans == 0) {
        cout << 1 << " " << a[8] << endl;
    }
    else {
        cout << ans << " " << ans + a[8] << endl;
    }
}

