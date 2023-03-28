#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 隣接リストで有向グラフを表す
using Graph = vector<vector<int>>;

// グラフのトポロジカルソート
vector<int> topological_sort(const Graph &G) {
	int n = G.size(); // 頂点数
	vector<int> ans; // ソート後の頂点のリスト
	vector<int> indeg(n, 0); // 各頂点の入次数

	// indegを更新
	for (int i = 0; i < n; i++) {
		for (auto j : G[i]) {
			// 頂点iから頂点jへ辺が伸びている
			indeg[j]++;
		}
	}

	// 幅優先探索によるソート
	queue<int> que; // 入次数が0の頂点のリスト
	for (int i = 0; i < n; i++) {
		if (indeg[i] == 0) que.push(i);
	}
	while (!que.empty()) {
		// 頂点を取り出す
		int i = que.front(); que.pop();
		// ansを更新
		ans.push_back(i);
		// indegを更新
		for (auto j : G[i]) {
			indeg[j]--;
			// 入次数が0になったらqueに入れる
			if (indeg[j] == 0) que.push(j);
		}
	}
	
	return ans;
}

int main() {
	string s;
	cin >> s;
	int n = s.size() + 1;
	// a[i] < a[i+1] <=> 頂点iから頂点i+1へ辺が伸びている
	// a[i] > a[i+1] <=> 頂点i+1から頂点iへ辺が伸びている
	// G[i] := iからつながる頂点のリスト
	Graph G(n);
	rep(i, n - 1) {
		if (s[i] == '<') G[i].push_back(i + 1);
		if (s[i] == '>') G[i + 1].push_back(i);
	}

	// トポロジカルソート
	vector<int> nodes = topological_sort(G);
	vector<long long> a(n, 0);
	// ソート順に各頂点を処理
	for (auto i : nodes) {
		for (auto j : G[i]) {
			// 頂点iからjへ辺が伸びている
			// a[i] < a[j]でなければならない
			a[j] = max(a[j], a[i] + 1);
		}
	}
	// 総和をとる
	long long ans = accumulate(a.begin(), a.end(), 0LL);
	cout << ans << endl;
	return 0;
}