#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, l, r, ans = 0;
    cin >> n;
    rep(i, n) {
        cin >> l >> r;
        ans += r - l + 1;
    }
    cout << ans << endl;
}
