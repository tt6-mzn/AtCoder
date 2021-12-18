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
    dsu d(n);
    vector<int> ans;
    int now = 0;
    ans.push_back(now);
    for (int i = n - 1; i >= 1; i--) {
        // 頂点iを追加
        set<int> st;
        now++;
        for (int node : G[i]) {
            if (node > i) {
                // iに隣接する頂点で、それ以前に追加済み
                st.insert(d.leader(node));
                d.merge(i, node); // iとnodeを連結
            }
        }
        now -= st.size();
        ans.push_back(now);
    }
    reverse(ans.begin(), ans.end());
    rep(i, ans.size()) {
        cout << ans[i] << endl;
    }
    return 0;
}