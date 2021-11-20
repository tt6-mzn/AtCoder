#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, x;
    cin >> n >> x;
    x--;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    vector<bool> know(n, false);
    know[x] = true;
    while (know[a[x]] == false) {
        x = a[x];
        know[x] = true;
    }
    int ans = 0;
    rep(i, n) {
        if (know[i]) ans++;
    }
    cout << ans << endl;
}