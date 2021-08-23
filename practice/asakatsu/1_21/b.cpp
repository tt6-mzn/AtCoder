#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int l, h;
    cin >> l >> h;
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    rep(i, n) {
        if (h < a[i]) {
            cout << -1 << endl;
        }
        else if (l <= a[i]) {
            cout << 0 << endl;
        }
        else {
            cout << l - a[i] << endl;
        }
    }
}