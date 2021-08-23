#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int a, b;
    cin >> a >> b;
    int k;
    cin >> k;
    vector<int> p(k);
    rep(i, k) cin >> p[i];
    vector<bool> seen(110, false);
    seen[a] = true;
    rep(i, k) {
        if (seen[p[i]]) {
            cout << "NO" << endl;
            return 0;
        }
        seen[p[i]] = true;
    }
    if (seen[b]) {
        cout << "NO" << endl;
        return 0;
    }
    else {
        cout << "YES" << endl;
    }
}
