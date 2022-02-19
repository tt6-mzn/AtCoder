#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> x;
vector<bool> seen;
vector<vector<int>> ans;

void dfs(const vector<vector<int>>& tree, int v) {
	seen[v] = true;
	if (tree[v].size() == 0) {
		ans[v].push_back(x[v]);
		return;
	}
	priority_queue<int> que;
	que.push(x[v]);
	for (auto next_v : tree[v]) {
		if (seen[next_v]) continue;
		dfs(tree, next_v);
		for (int t : ans[next_v]) {
			que.push(t);
		}
	}
	
	// priority_queue<int> tmp;
	// if (v == 1) {
	// 	while (!que.empty()) {
	// 		tmp.push(que.top());
	// 		cout << que.top() << endl; que.pop();
	// 	}
	// 	while (!tmp.empty()) {
	// 		que.push(tmp.top()); tmp.pop();
	// 	}
	// }

	int s = que.size();
	rep(i, min(s, 20)) {
		ans[v].push_back(que.top());
		que.pop();
	}
}

int main() {
	int n, q;
	cin >> n >> q;
	x.assign(n, 0);
	rep(i, n) cin >> x[i];
	vector<vector<int>> tree(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}

	seen.assign(n, false);
	rep(i, n) {
		vector<int> t;
		ans.push_back(t);
	}

	dfs(tree, 0);

	// rep(_, ans.size()) { rep(__, ans[_].size()) { cout << ans[_][__] << " "; } cout << endl; }
	
	rep(i, q) {
		int v, k;
		cin >> v >> k;
		v--; k--;
		cout << ans[v][k] << endl;
	}
	return 0;
}