#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n), c(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    rep(i, n) cin >> c[i];
    rep(i, n) {
        a[i]--;
        b[i]--;
        c[i]--;
    }
    vector<long long> cnt_c(n, 0);
    rep(i, n) cnt_c[c[i]]++;
    vector<vector<long long>> ind_b(n);
    rep(i, n) ind_b[b[i]].push_back(i);
    vector<long long> ans_b(n, 0);
    rep(i, n) {
        for (long long i_b : ind_b[i]) {
            ans_b[i] += cnt_c[i_b];
        }
    }
    long long ans = 0;
    for (long long a_i : a) {
        ans += ans_b[a_i];
    }
    cout << ans << endl;
}