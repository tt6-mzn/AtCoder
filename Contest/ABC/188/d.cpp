#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long N, C;
    cin >> N >> C;
    vector<long long> a(N), b(N), c(N);
    rep(i, N) {
        cin >> a.at(i) >> b.at(i) >> c.at(i);
    }
    vector<long long> imos(100000, 0);
    long long ans = 0;
    rep(i, N) {
        if (a.at(i) < 100000) {
            imos[a.at(i)] += c.at(i);
        }
        if (b.at(i) < 100000) {
            imos[b.at(i) + 1] -= c.at(i);
        }
    }
    for (int i = 1; i < 100000; i++) {
        imos[i] += imos[i - 1];
    }
    for (int i = 0; i < 100000; i++) {
        ans += min(C, imos[i]);
    }
    long long p;
    p = imos[100000 - 1];
    imos.assign(100000, 0);
    imos[0] += p;
    rep(i, N) {
        cout << i << endl;
        if (a.at(i) >= 100000) {
            imos[a.at(i) - 100000] += c.at(i);
        }
        if (b.at(i) >= 100000) {
            imos[b.at(i) - 100000 + 1] -= c.at(i);
        }
    }
    for (int i = 1; i < 100000; i++) {
        imos[i] += imos[i - 1];
    }
    for (int i = 0; i < 100000; i++) {
        ans += min(C, imos[i]);
    }
    cout << ans << endl;
}