#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long ans = 0;

void rec(int i, int n, long long now, long long x, vector<vector<long long>> &a) {
    if (i == n) {
        if (now == x) ans++;
        return;
    }
    rep(j, a[i].size()) {
        if ((x + now - 1) / now >= a[i][j]) {
            rec(i + 1, n, now * a[i][j], x, a);
        }
    }
}

int main() {
    long long n, x;
    cin >> n >> x;
    vector<vector<long long>> a(n);
    rep(i, n) {
        int l;
        cin >> l;
        rep(j, l) {
            int a_i;
            cin >> a_i;
            a[i].push_back(a_i);
        }
    }
    rec(0, n, 1, x, a);
    cout << ans << endl;
    return 0;
}