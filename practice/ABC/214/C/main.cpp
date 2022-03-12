#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const long long INF = 1LL << 62;

class Edge {
public:
	// int from;
	int to;
	long long cost;
	Edge() {};
	Edge(/*int from,*/ int to, long long cost)
		: /*from(from),*/ to(to), cost(cost) {};
};

using Graph = vector<vector<Edge>>; // 隣接リスト
using P	= pair<long long, int>; // (距離, 頂点)の組

/* ダイクストラ法で頂点sから各頂点への最短距離を求める
 * O(ElogV), E: 辺数, V: 頂点数
 * G: 隣接行列, s: 始点
 * 返り値: 各頂点への最短距離が入った配列
 * 経路を具体的に求めるときは、prevを用いる
*/
vector<long long> dijkstra(const Graph &G, int s) {
	int n = G.size(); // 頂点数
	vector<long long> dist(n, INF); // sから各頂点への最短距離
	// vector<int> prev(n, -1); // prev[v] := sからvへ最短距離で移動するとき、vへ移動する直前にいた頂点
	priority_queue<P, vector<P>, greater<P>> que;
	dist[s] = 0;
	que.emplace(dist[s], s);
	while (!que.empty()) {
		long long d; int v; 
		tie(d, v) = que.top(); que.pop();
		if (dist[v] < d) continue;
		for (const Edge& e : G[v]) {
			if (dist[e.to] > dist[v] + e.cost) {
				dist[e.to] = dist[v] + e.cost;
				// prev[e.to] = v;
				que.emplace(dist[e.to], e.to);
			}
		}
	}
	return dist;
}

int main() {
	int n;
	cin >> n;
	Graph G(n + 1);
	rep(i, n) {
		long long s;
		cin >> s;
		Edge e;
		if (i + 2 < n + 1) e.to = i + 2;
		else e.to = 1;
		e.cost = s;
		G[i + 1].push_back(e);
	}
	rep(i, n) {
		long long t;
		cin >> t;
		Edge e(i + 1, t);
		G[0].push_back(e);
	}
	auto dist = dijkstra(G, 0);
	for (int i = 1; i < n + 1; i++) cout << dist[i] << endl;
	return 0;
}