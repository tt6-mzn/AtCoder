#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w;
    cin >> h >> w;
    vector<string> bd(h);
    rep(i, h) cin >> bd[i];
    vector<vector<int>> dp(h, vector<int>(w, 0));
    dp[0][0] = 1;
    rep(i, h) rep(j, w) {
        if (bd[i][j] == '#') continue;
        if (i - 1 >= 0 && bd[i - 1][j] == '.' && dp[i - 1][j] > 0) dp[i][j] = max(dp[i][j], dp[i - 1][j] + 1);
        if (j - 1 >= 0 && bd[i][j - 1] == '.' && dp[i][j - 1] > 0) dp[i][j] = max(dp[i][j], dp[i][j - 1] + 1);
    }
    int ans = -1;
    rep(i, h) rep(j, w) {
        ans = max(ans, dp[i][j]);
    }
    // rep(i, h) {
    //     rep(j, w) {
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    cout << ans << endl;
    return 0;
}