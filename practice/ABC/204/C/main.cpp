#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

vector<int> bfs(const vector<vector<int>> &G, int s) {
	/* G: グラフを表す配列, s: 探索の始点となる頂点 */
	int n = (int)G.size(); // 頂点数
	vector<int> dist(n, -1); // 全頂点を「未訪問」に追加
	queue<int> que;

	// 初期条件(頂点sを初期頂点とする)
	dist[s] = 0;
	que.push(s);

	while (!que.empty()) {
		int v = que.front(); que.pop(); // 先頭要素を取り出す

		// vからたどれる頂点をすべて調べる
		for (int x : G[v]) {
			// すでに発見済みの頂点は探索しない
			if (dist[x] != -1) continue;

			// 新たな頂点xに対して距離を更新しqueに追加
			dist[x] = dist[v] + 1;
			que.push(x);
		}
	}
	return dist;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> G(n);
	rep(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
	}
	int ans = 0;
	rep(i, n) {
		vector<int> dist = bfs(G, i);
		int cnt = 0;
		for (int d : dist) {
			if (d >= 0) cnt++;
		}
		ans += cnt;
	}
	cout << ans << endl;
}