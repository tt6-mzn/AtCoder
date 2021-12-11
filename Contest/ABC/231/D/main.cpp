#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> deg(n, 0);
    dsu uf(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        deg[a]++;
        deg[b]++;
        if (deg[a] >= 3 || deg[b] >= 3) {
            cout << "No" << endl;
            return 0;
        }
        if (uf.same(a, b)) {
            cout << "No" << endl;
            return 0;
        }
        uf.merge(a, b);
    }
    cout << "Yes" << endl;
    return 0;
}