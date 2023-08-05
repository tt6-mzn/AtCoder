#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> G(n + 1, 0);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        G[b]++;
    }
    int cnt = 0;
    int ans = 0;
    for (int i = 1; i < n + 1; i++) {
        if (G[i] == 0) {
            cnt++;
            ans = i;
        }
    }
    if (cnt == 1) {
        cout << ans << endl;
    } else {
        cout << -1 << endl;
    }
    return 0;
}