#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    rep(i, n - 1) cin >> b[i];
    int ans = b[n - 2];
    for (int i = n - 2; i > 0; i--) {
        ans += min(b[i], b[i - 1]);
    }
    ans += b[0];
    cout << ans << endl;
}