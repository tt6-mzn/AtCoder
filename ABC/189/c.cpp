#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    for (int x : a) {
        int l = 0, r;
        while (l < n) {
            while (l < n && a[l] < x) {
                l++;
            }
            r = l;
            while (r < n && a[r] >= x) {
                r++;
            }
            ans = max(ans, (r - l) * x);
        }
    }
    cout << ans << endl;
}
