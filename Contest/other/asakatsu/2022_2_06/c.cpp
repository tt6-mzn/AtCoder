#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n) cin >> b[i];
    bool flg = true;
    rep(i, n) {
        if (b[i] > i + 1) {
            flg = false;
        }
    }
    if (flg == false) {
        cout << -1 << endl;
    }
    vector<int> a(n);
    vector<bool> seen(n, false);
    rep(i, n) {
        int k = 0;
        rep(j, n) {
            if (seen[j] == false && b[j] == j + 1) {
                k = j;
            }
            a[n - k - 1] = b[k];
            b[k] = true;
        }
    }
    rep(i, n) {
        cout << a[i] << endl;
    }
}
