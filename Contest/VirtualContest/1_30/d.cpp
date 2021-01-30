#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i, n) cin >> h[i];
    vector<int> dp(n + 1, 0);
    dp[2] = abs(h[1] - h[0]);
    for (int i = 3; i <= n; i++) {
        dp[i] = min(dp[i - 1] + abs(h[i - 1] - h[i - 2]), dp[i - 2] + abs(h[i - 1] - h[i - 3]));
    }
    cout << dp[n] << endl;
}
