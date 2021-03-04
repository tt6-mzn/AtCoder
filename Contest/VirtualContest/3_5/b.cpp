#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, s, t;
    cin >> n >> s >> t;
    long long w;
    cin >> w;
    vector<int> a(n);
    for (int i = 1; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    if (s <= w && w <= t) {
        ans++;
    }
    for (int i = 1; i < n; i++) {
        w += a[i];
        if (s <= w && w <= t) {
            ans++;
        }
    }
    cout << ans << endl;
}
