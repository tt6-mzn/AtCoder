#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template<class T> void chmin(T& a, T b) {
    if (a > b) {
        a = b;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> dp(n, 1100100100);
    dp[0] = 0;
    rep(i, n) {
        for (int j = 1; j <= k; j++) {
            if (i + j < n) {
                chmin(dp[i + j], dp[i] + abs(h[i] - h[i + j]));
            }
        }
    }
    cout << dp[n - 1] << endl;
}
