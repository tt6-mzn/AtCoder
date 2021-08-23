#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dfs(int v, long long m, vector<bool> seen, int &n, int &k, vector<vector<int>> &T) {
    seen.at(v) = true;
    bool flg = true;
    int ret = 0;
    rep(i, n) {
        if(seen.at(i) == false) {
            flg = false;
            ret += dfs(i, m + T[v][i], seen, n, k, T);
        }
    }
    if(flg) {
        if((m + T[v][0]) == k) {
            return 1;
        }
        else {
            return 0;
        }
    }
    else {
        return ret;
    }
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<vector<int>> T(n, vector<int>(n));
    rep(i, n) rep(j, n) cin >> T.at(i).at(j);
    vector<bool> seen(n, false);
    cout << dfs(0, 0, seen, n, k, T) << endl;
}