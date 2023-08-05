#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i, n) cin >> p[i];
    int x = 0;
    for (int i = 1; i < n; i++) {
        x = max(x, p[i] - p[0] + 1);
    }
    cout << x << endl;
    return 0;
}