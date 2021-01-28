#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    int s = 0, t = 0, u = 0;
    int ans = 1;
    while (s < n - 1) {
        while (t < n - 1 && h[t] < h[t + 1]) {
            t++;
        }
        u = t;
        while (u < n - 1 && h[u] > h[u + 1]) {
            u++;
        }
        ans = max(u - s + 1, ans);
        s = u;
        t = u;
    }
    cout << ans << endl;
}