#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<pair<long long, long long>>> g;
vector<long long> memo; // kから頂点iまでにかかる最小コスト

void dfs(long long i, long long cost) {
    memo[i] = cost;
    for (int j = 0; j < g[i].size(); j++) {
        if (memo[g[i][j].first] == -1) {
            dfs(g[i][j].first, cost + g[i][j].second);
        }
    }
}

int main() {
    long long n;
    cin >> n;
    g.resize(n);
    rep(i, n - 1) {
        long long a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    long long q, k;
    cin >> q >> k;
    k--;
    vector<pair<long long, long long>> query(q);
    rep(i, q) {
        cin >> query[i].first >> query[i].second;
        query[i].first--; query[i].second--;
    }

    memo.assign(n, -1);
    dfs(k, 0);

    rep(i, q) {
        int x, y;
        x = query[i].first;
        y = query[i].second;
        cout << memo[x] + memo[y] << endl;
    }
}