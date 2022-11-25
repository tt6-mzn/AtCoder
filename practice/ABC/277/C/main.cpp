#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)


int main() {
	int n;
	cin >> n;
	map<int, vector<int>> G;
	rep(i, n) {
		int a, b;
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}

	int ans = 0;
	map<int, bool> memo;
	queue<int> que;

	que.push(1);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		if (memo[v]) continue;
		memo[v] = true;
		ans = max(ans, v);
		for (int next : G[v]) que.push(next);
	}
	cout << ans << endl;
	return 0;
}