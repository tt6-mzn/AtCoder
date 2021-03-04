#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int ans = 0;
    rep(i, n) {
        if ((i + 1) % 2 == 1 && a[i] % 2 == 1) {
            ans++;
        }
    }
    cout << ans << endl;
}