#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<bool>> G(n, vector<bool>(n, false));
	rep(_, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u][v] = true;
		G[v][u] = true;
	}
	int ans = 0;
	rep(i, n) rep(j, i) rep(k, j) {
		if (G[i][j] && G[j][k] && G[k][i]) ans++;
	}
	cout << ans << endl;
	return 0;
}