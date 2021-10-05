#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> ans;

void dfs(vector<vector<int>> &G, int crr, int pre) {
	ans.push_back(crr);
	for (int nxt : G[crr]) {
		if (nxt != pre) {
			dfs(G, nxt, crr);
			ans.push_back(crr);
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> G(n + 1);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	for (int i = 1; i <= n; i++) sort(G[i].begin(), G[i].end());
	dfs(G, 1, -1);
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++) {
		cout << " " << ans[i];
	}
	cout << endl;
}