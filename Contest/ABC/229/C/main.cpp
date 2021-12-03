#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, w;
    cin >> n >> w;
    vector<pair<long long, long long>> ab(n);
    rep(i, n) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end(), greater<pair<long long, long long>>());
    long long now = 0;
    long long ans = 0;
    long long i = 0;
    while (i < n && now + ab[i].second <= w) {
        ans += ab[i].first * ab[i].second;
        now += ab[i].second;
        i++;
    }
    if (i < n) {
        ans += ab[i].first * (w - now);
    }
    cout << ans << endl;
    return 0;
}