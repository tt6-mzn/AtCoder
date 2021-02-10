#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    bool flg = true;
    rep(i, n - 1) {
        if (a[i] != x) {
            cout << a[i] << " ";
            flg = false;
        }
    }
    if (a[n - 1] != x) {
        cout << a[n - 1] << endl;
        flg = false;
    }
    if (flg) {
        cout << endl;
    }
}
