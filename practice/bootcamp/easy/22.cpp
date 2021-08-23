#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int ans = 0;
    int i = 0;
    while (i < n && x - a[i] >= 0) {
        x -= a[i];
        ans++;
        i++;
    }
    if (x != 0) {
        ans = max(ans - 1, 0);
    }
    cout << ans << endl;
}