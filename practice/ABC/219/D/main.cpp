#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i] >> b[i];
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(x + 1, vector<int>(y + 1, 100100100)));
    rep(i, n + 1) dp[i][0][0] = 0;
    for (int i = 1; i < n + 1; i++) {
        for (int j = 0; j < x + 1; j++) {
            for (int k = 0; k < y + 1; k++) {
                dp[i][j][k] = dp[i - 1][j][k];
                dp[i][j][k] = min(dp[i][j][k], dp[i - 1][max(0, j - a[i - 1])][max(0, k - b[i - 1])] + 1);
            }
        }
    }
    if (dp[n][x][y] == 100100100) cout << -1 << endl;
    else cout << dp[n][x][y] << endl;
    return 0;
}