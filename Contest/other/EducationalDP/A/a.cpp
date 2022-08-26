#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> dp(n, 1100100100);
    dp[0] = 0;
    rep(i, n) {
        if (i + 1 < n) {
            chmin(dp[i + 1], dp[i] + abs(h[i] - h[i + 1]));
        }
        if (i + 2 < n) {
            chmin(dp[i + 2], dp[i] + abs(h[i] - h[i + 2]));
        }
    }
    cout << dp[n - 1] << endl;
}