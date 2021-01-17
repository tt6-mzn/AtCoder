#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

/* union-find木を実装 */
int root(int x, vector<int> &par, vector<int> &rank) {
    if(par.at(x) == x) {
        return x;
    }
    par.at(x) = root(par.at(x), par, rank);
    return par.at(x);
}

bool same(int x, int y, vector<int> &par, vector<int> &rank) {
    return root(x, par, rank) == root(y, par, rank);
}

void unite(int x, int y, vector<int> &par, vector<int> &rank) {
    x = root(x, par, rank);
    y = root(y, par, rank);
    if(x == y) return;
    if(rank.at(x) < rank.at(y)) {
        par.at(x) = y;
    }
    else {
        par.at(y) = x;
        if(rank.at(x) == rank.at(y)) rank.at(x)++;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> ab(m);
    rep(i, m) {
        cin >> ab.at(i).first >> ab.at(i).second;
        ab.at(i).first--;
        ab.at(i).second--;
    }
    vector<int> par(n);
    vector<int> rank(n);
    rep(i, n) {
        par.at(i) = i;
        rank.at(i) = 0;
    }
    rep(i, m) {
        unite(ab.at(i).first, ab.at(i).second, par, rank);
    }
    vector<int> num(n);
    rep(i, n) {
        num.at(root(i, par, rank))++;
    }
    int ans = 0;
    rep(i, n) {
        ans = max(ans, num.at(i));
    }
    cout << ans << endl;
}