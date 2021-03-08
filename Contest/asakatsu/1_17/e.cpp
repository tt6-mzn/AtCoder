#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<vector<int>> grid(n + 1, vector<int>(n + 1, 0));
    rep(i, n) {
        int x, y;
        cin >> x >> y;
        grid[x][y] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            grid[i][j] = grid[i][j] + grid[i - 1][j] + grid[i][j - 1] - grid[i - 1][j - 1];
        }
    }

    rep(i, n + 1) {
        rep(j, n + 1) {
            
        }
    }
}