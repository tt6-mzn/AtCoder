#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, d;
    cin >> n >> d;
    vector<pair<long long, long long>> lr(n);
    rep(i, n) cin >> lr[i].first >> lr[i].second;
    sort(lr.begin(), lr.end(), [](
        pair<long long, long long>& a, pair<long long, long long>& b) { return a.second < b.second;}
    );
    long long nl, nr;
    nl = lr[0].first;
    nr = lr[0].second;
    long long ans = 1;
    for (int i = 1; i < n; i++) {
        if (nr + d <= lr[i].first) {
            ans++;
            nl = lr[i].first;
            nr = lr[i].second;
        }
    }
    cout << ans << endl;
    return 0;
}