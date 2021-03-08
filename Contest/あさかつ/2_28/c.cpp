#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans1 = 1, ans2 = 1;
    rep(i, n) ans1 *= 3;
    rep(i, n) {
        if (a[i] % 2 == 0) {
            ans2 *= 2;
        }
    }
    cout << ans1 - ans2 << endl;
}
