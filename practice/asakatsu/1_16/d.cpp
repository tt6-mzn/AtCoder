#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dfs(int node, int cost, vector<vector<pair<int, int>>>& g, vector<bool>& seen, vector<int>& memo) {
    seen[node] = true;
    rep(i, g[node].size()) {
        if (seen[g[node][i].first] == false) {
            memo[g[node][i].first] = cost + g[node][i].second;
            dfs(g[node][i].first, cost + g[node][i].second, g, seen, memo);
        }
    }
}

int main() {
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> g(n);
    rep(i, n - 1) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }
    int q, k;
    cin >> q >> k;
    vector<bool> seen(n, false);
    vector<int> memo(n);
    dfs(k, 0, g, seen, memo);
    rep(i, n) cout << memo[i] << endl;
}