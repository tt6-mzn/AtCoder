#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i, q) {
        int x;
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        int index = it - a.begin();
        cout << n - index << endl;
    }
    return 0;
}