#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> indeg(n, 0);
    vector<vector<int>> G(n);
    rep(i, m) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        indeg[b]++;
        G[a].push_back(b);
    }
    priority_queue<int, vector<int>, greater<int>> heap;
    rep(i, n) {
        if (indeg[i] == 0) heap.push(i);
    }
    vector<int> ans;
    while (!heap.empty()) {
        int i = heap.top(); heap.pop();
        ans.push_back(i + 1);
        for (int j : G[i]) {
            indeg[j]--;
            if (indeg[j] == 0) heap.push(j);
        }
    }
    if (ans.size() == n) {
        cout << ans[0];
        for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
        cout << endl;
    }
    else {
        cout << -1 << endl;
    }
    return 0;
}