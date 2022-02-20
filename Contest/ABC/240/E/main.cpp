#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


vector<bool> seen;
vector<pair<int, int>> ans;
void dfs(const vector<vector<int>>& tree, int v, int left) {
	seen[v] = true;
	ans[v].first = left;
	if (tree[v].size() == 0) {
		ans[v].second = left;
		return;
	}
	ans[v].second = left;
	bool flg = true;
	for (auto next_v : tree[v]) {
		if (seen[next_v]) continue;
		if (flg) {
			dfs(tree, next_v, ans[v].second);
			flg = false;
		}
		else dfs(tree, next_v, ans[v].second + 1);
		ans[v].second = ans[next_v].second;
	}
}

int main() {
	int n;
	cin >> n;
	seen.assign(n, false);
	ans.resize(n);
	vector<vector<int>> tree(n);
	rep(i, n - 1) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	dfs(tree, 0, 1);
	rep(i, n) {
		cout << ans[i].first << " " << ans[i].second << endl;
	}
	return 0;
}