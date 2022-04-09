#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
vector<vector<int>> tree;
vector<int> dist;

void dfs(int v, int par, int depth) {
	dist[v] = depth;
	for (int next : tree[v]) {
		if (next != par) dfs(next, v, depth + 1);
	}
}

int main() {
	cin >> n;
	tree.resize(n);
	dist.resize(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		tree[a].push_back(b);
		tree[b].push_back(a);
	}
	dfs(0, -1, 0);
	int v, d = -1;
	rep(i, n) {
		if (d < dist[i]) {
			v = i;
			d = dist[i];
		}
	}
	dfs(v, -1, 0);
	int ans = -1;
	rep(i, n) ans = max(ans, dist[i]);
	cout << ans + 1 << endl;
	return 0;
}