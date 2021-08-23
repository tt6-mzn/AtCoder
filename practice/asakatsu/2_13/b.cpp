#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> b(n);
    vector<int> ans(n);
    rep(i, n) cin >> b[i];
    rep(i, n) {
        if (i + 1 < b[i]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int cnt = 0;
    while (b.empty() == false) {
        int k;
        rep(j, b.size()) {
            if (j + 1 == b[j]) {
                k = j;
            }
        }
        ans[cnt] = k + 1;
        b.erase(b.begin() + k);
        cnt++;
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << endl;
    }
}
