#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

int main() {
	int n, m, k, s, t, x;
	cin >> n >> m >> k >> s >> t >> x;
	s--; t--; x--;
	vector<vector<int>> G(n);
	rep(_, m) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	// dp[i][j] = sからxを偶数回通ってjに行く、長さkのpathの本数
	vector<vector<mint>> dp_even(k + 1, vector<mint>(n, 0));
	// dp[i][j] = sからxを奇数回通ってjに行く、長さkのpathの本数
	vector<vector<mint>> dp_odd(k + 1, vector<mint>(n, 0));
	dp_even[0][s] = 1; // sからsへ行く長さ0のpathは、xを0回通る
	for (int i = 1; i <= k; i++) {
		rep(j, n) {
			if (j == x) {
				for (int v : G[j]) {
					dp_even[i][j] += dp_odd[i - 1][v];
					dp_odd[i][j] += dp_even[i - 1][v];
				}
			}
			else {
				for (int v : G[j]) {
					dp_even[i][j] += dp_even[i - 1][v];
					dp_odd[i][j] += dp_odd[i - 1][v];
				}
			}
		}
	}
	cout << dp_even[k][t].val() << endl;
	return 0;
}