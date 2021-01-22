#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    rep(i, 2) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }

    int ans = 0;
    rep(i, n) {
        int score = 0;
        rep(j, n) {
            if (j == i)
            {
                score += a[0][j] + a[1][j];
            }
            else if (j > i)
            {
                score += a[1][j];
            }
            else
            {
                score += a[0][j];
            }
        }
        ans = max(ans, score);
    }

    cout << ans << endl;
}