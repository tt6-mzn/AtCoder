#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const int inf = 1<<30;

int main() {
	int n, m;
	cin >> n >> m;
	vector<tuple<int, int, long long>> edges;
	vector<vector<long long>> dist(n, vector<long long>(n, inf));
	rep(i, m) {
		int a, b; long long c;
		cin >> a >> b >> c;
		a--; b--;
		dist[a][b] = c;
		dist[b][a] = c;
		edges.emplace_back(a, b, c);
	}
	rep(k, n) rep(i, n) rep(j, n) {
		dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
	}
	int ans = 0;
	for (auto &t : edges) {
		int a, b; long long c;
		tie(a, b, c) = t;
		bool flg = true;
		rep(i, n) {
			if (dist[a][i] + dist[i][b] <= c) flg = false;
		}
		if (!flg) ans++;
	}
	cout << ans << endl;
	return 0;
}