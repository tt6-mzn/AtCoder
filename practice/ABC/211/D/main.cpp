#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    vector<pair<long long, long long>> bfs(n);
    long long mod = 1000000007;
    rep(i, n) { bfs[i].first = 1100100100; bfs[i].second = 0; }
    bfs[0] = make_pair(0, 1); // 0時間 1通り
    queue<int> que;
    vector<bool> seen(n, false);
    que.push(0);
    while (!que.empty()) {
        int v = que.front(); que.pop();
        if (seen[v]) continue;
        seen[v] = true;
        for (int next : G[v]) {
            if (seen[next]) continue;
            if (bfs[next].first > bfs[v].first + 1) {
                bfs[next].first = bfs[v].first + 1;
                bfs[next].second = bfs[v].second;
            }
            else if (bfs[next].first == bfs[v].first + 1) {
                bfs[next].second = (bfs[next].second + bfs[v].second) % mod;
            }
            que.push(next);
        }
    }
    cout << bfs[n - 1].second << endl;
    return 0;
}