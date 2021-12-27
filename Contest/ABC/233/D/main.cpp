#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, k;
    cin >> n >> k;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    vector<long long> s(n + 1, 0);
    for (int i = 1; i < n + 1; i++) s[i] = s[i - 1] + a[i - 1];
    map<long long, long long> mp;
    rep(i, n + 1) mp[s[i]]++;

    long long ans = 0;
    rep(i, n + 1) {
        mp[s[i]]--;
        ans += mp[s[i] + k];
    }
    cout << ans << endl;
    // cout << s[0];
    // for (int i = 1; i < s.size(); i++) cout << " " << s[i];
    // cout << endl;

    return 0;
}