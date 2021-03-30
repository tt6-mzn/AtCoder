#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    x--;
    y--;
    vector<string> bd(h);
    rep(i, h) cin >> bd[i];
    int ans = 0;
    int j = y;
    while (0 <= j && bd[x][j] == '.') {
        j--;
        ans++;
    }
    j = y + 1;
    while (j < w && bd[x][j] == '.') {
        j++;
        ans++;
    }
    int i = x - 1;
    while (0 <= i && bd[i][y] == '.') {
        i--;
        ans++;
    }
    i = x + 1;
    while (i < h && bd[i][y] == '.') {
        i++;
        ans++;
    }
    cout << ans << endl;
}