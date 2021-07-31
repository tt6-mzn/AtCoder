#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long dfs(long long node, long long goal, vector<vector<long long>> &G, vector<bool> &seen, vector<long long> &memo, long long mod) {
	if (node == goal) return 1;
	if (seen[node] == true) return 0;
	long long ret = 0;
	for (long long nextnode : G[node]) {
		if (memo[nextnode] != -1) ret = (ret + memo[nextnode]) % mod;
		else {
			seen[nextnode] = true;
			memo[nextnode] = dfs(nextnode, goal, G, seen, memo, mod);
			ret += memo[nextnode];
			seen[nextnode] = false;
		}
	}
	memo[node] = ret;
	return ret;
}

int main() {
	long long n, m;
	cin >> n >> m;
	vector<vector<long long>> G(n, vector<long long>());
	rep(i, m) {
		long long a, b;
		cin >> a >> b;
		G[a - 1].push_back(b - 1);
		G[b - 1].push_back(a - 1);
	}
	vector<bool> seen(n, false);
	vector<long long> memo(n, -1);
	cout << dfs(0, n - 1, G, seen, memo, 1000000007) << endl;
}