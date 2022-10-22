#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<vector<int>> G_;

int dfs(int v) {
	if (G_[v].size() == 0) return 1;
	int ret = 0;
	for (int nv : G_[v]) ret = max(ret, dfs(nv) + 1);
	return ret;
}

int main() {
	int n, m; cin >> n >> m;
	vector<vector<int>> G(n);
	G_.resize(n);
	vector<int> deg(n, 0);
	rep(_, m) {
		int x, y; cin >> x >> y;
		x--; y--;
		G[y].push_back(x);
		G_[x].push_back(y);
		deg[x]++;
	}
	queue<int> que;
	rep(i, n) if (deg[i] == 0) que.push(i);
	vector<int> order;
	while (!que.empty()) {
		int v = que.front(); que.pop();
		order.push_back(v);
		for (auto nv : G[v]) if (--deg[nv] == 0) que.push(nv);
	}
	reverse(order.begin(), order.end());
	int root = order[0];
	cout << dfs(root) << endl;
	return 0;
}