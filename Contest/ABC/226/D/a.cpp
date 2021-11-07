#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<long long> x(n), y(n);
    rep(i, n) cin >> x[i] >> y[i];
    set<pair<long long, long long>> memo;
    rep(i, n) {
        rep(j, n) {
            if (i == j) continue;
            long long dx, dy;
            dx = x[i] - x[j];
            dy = y[i] - y[j];
            long long g = __gcd(abs(dx), abs(dy));
            dx /= g;
            dy /= g;
            memo.insert(make_pair(dx, dy));
        }
    }
    cout << memo.size() << endl;
}


