#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g1(n, vector<bool>(n, false)), g2(n, vector<bool>(n, false));
    vector<int> perm(n);
    rep(i, n) perm[i] = i;
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g1[a][b] = true;
        g1[b][a] = true;
    }
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        g2[a][b] = true;
        g2[b][a] = true;
    }
    do {
        bool flg = true;
        rep(i, n) rep(j, n) {
            if (g1[i][j] != g2[perm[i]][perm[j]]) flg = false;
        }
        if (flg) {
            cout << "Yes" << endl;
            return 0;
        }
    } while(next_permutation(perm.begin(), perm.end()));
    cout << "No" << endl;
    return 0;
}