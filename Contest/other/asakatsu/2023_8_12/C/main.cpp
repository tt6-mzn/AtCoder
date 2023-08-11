#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n);
    rep(_, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if (n - 1 != m) {
        cout << "No" << endl;
        return 0;
    }
    int now = 0;
    while (now < n && G[now].size() != 1)
        now++;
    if (now == n) {
        cout << "No" << endl;
        return 0;
    }
    int pre = now;
    now = G[now][0];
    vector<bool> seen(n, false);
    seen[pre] = true;
    while (!seen[now]) {
        seen[now] = true;
        for (auto v : G[now]) {
            if (v != pre) {
                pre = now;
                now = v;
                break;
            }
        }
    }
    if (all_of(seen.begin(), seen.end(), [](auto f) { return f; })) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}