#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    dsu uf(n);
    rep(_, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        uf.merge(u, v);
    }
    set<int> st;
    rep(i, n) st.insert(uf.leader(i));
    cout << st.size() << endl;
    return 0;
}