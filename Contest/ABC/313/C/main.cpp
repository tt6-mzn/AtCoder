#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    long long sum = accumulate(a.begin(), a.end(), 0LL);
    long long avg = sum / n;
    long long ans1 = 0;
    long long ans2 = 0;
    for (auto ai : a) {
        ans1 += max(0LL, ai - (avg + 1));
        ans2 += max(0LL, avg - ai);
    }
    // cout << ans1 << " " << ans2 << endl;
    cout << max(ans1, ans2) << endl;
    return 0;
}