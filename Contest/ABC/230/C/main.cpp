#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n, a, b;
    cin >> n >> a >> b;
    long long p, q, r, s;
    cin >> p >> q >> r >> s;
    vector<vector<bool>> bd(q - p + 1, vector<bool>(s - r + 1, false));
    rep(row, q - p + 1) {
        rep(col, s - r + 1) {
            long long i, j;
            i = p + row;
            j = r + col;
            if (i - j == a - b) bd[row][col] = true;
            if (i + j == a + b) bd[row][col] = true;
        }
    }
    rep(i, q - p + 1) {
        rep(j, s - r + 1) {
            if (bd[i][j]) cout << "#";
            else cout << ".";
        }
        cout << endl;
    }
    return 0;
}