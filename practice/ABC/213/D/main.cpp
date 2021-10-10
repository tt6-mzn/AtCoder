#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void dfs(vector<priority_queue<int>> &G, int v, vector<bool> &memo, vector<int> &ans) {
	ans.push_back(v);
	memo[v] = true;
	while (!G[v].empty()) {
		int next = (-1) * G[v].top(); G[v].pop();
		if (!memo[next]) {
			dfs(G, next, memo, ans);
			ans.push_back(v);
		}
	}
}

int main() {
	int n;
	cin >> n;
	vector<priority_queue<int>> G(n + 1);
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		G[a].push((-1) * b);
		G[b].push((-1) * a);
	}
	vector<bool> memo(n + 1, false);
	vector<int> ans;
	dfs(G, 1, memo, ans);
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++) {
		cout << " " << ans[i];
	}
	cout << endl;
}