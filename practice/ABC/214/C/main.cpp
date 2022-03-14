#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

const long long INF = 1LL << 62;

class Edge {
public:
	int from; // 辺の始点
	int to; // 辺の終点
	long long cost = 1; // 辺の重み
	Edge() {};
	Edge(int from, int to) : from(from), to(to) {};
	Edge(int from, int to, long long cost)
		: from(from), to(to), cost(cost) {};
};

class Graph {
private:
	vector<vector<Edge>> _Graph; // _Graph[i]:=頂点iから出る辺
	vector<long long> _distance; // dijkstra()の結果が格納される
	vector<int> _prev; // dijkstra()の結果が格納される
public:
	int V; // 頂点数
	int E = 0; // 辺数
	Graph(int V);
	void add_edge(int from, int to);
	void add_edge(int from, int to, long long cost);
	void dijkstra(int s); // ダイクストラ法
	long long distance(int to) const; // ダイクストラ法の結果に基づいて頂点toまでの最短距離を返す
	vector<int> path(int to) const; // ダイクストラ法の結果に基づいて頂点toまでのルートを返す
};

/* 頂点数と辺の数を指定して初期化 */
Graph::Graph(int V) : V(V) {
	_Graph.resize(V);
}

void Graph::add_edge(int from, int to) {
	if (from < 0 || V <= from) {
		throw out_of_range("[Graph::add_edge] index out of range");
		exit(0);
	}
	if (to < 0 || V <= to) {
		throw out_of_range("[Graph::add_edge] index out of range");
		exit(0);
	}
	Edge tmp(from, to);
	_Graph.at(from).push_back(tmp);
	E++;
}

void Graph::add_edge(int from, int to, long long cost) {
	if (from < 0 || V <= from) {
		throw out_of_range("[Graph::add_edge] index out of range");
		exit(0);
	}
	if (to < 0 || V <= to) {
		throw out_of_range("[Graph::add_edge] index out of range");
		exit(0);
	}
	Edge tmp(from, to, cost);
	_Graph.at(from).push_back(tmp);
	E++;
}

/* ダイクストラ法で頂点sから各頂点への最短距離を求める
 * 計算量はO(ElogV)
 * 返り値: 各頂点への最短距離が入った配列
*/
void Graph::dijkstra(int s) {
	_distance.assign(V, INF);
	_prev.assign(V, -1);
	priority_queue<
		pair<long long, int>,
		vector<pair<long long, int>>,
		greater<pair<long long, int>>> que;
	_distance.at(s) = 0;
	que.emplace(_distance.at(s), s);
	while (!que.empty()) {
		long long d; int v;
		tie(d, v) = que.top(); que.pop();
		if (_distance.at(v) < d) continue;
		for (const Edge& e : _Graph.at(v)) {
			if (_distance.at(e.from) + e.cost < _distance.at(e.to)) {
				_distance.at(e.to) = _distance.at(e.from) + e.cost;
				_prev.at(e.to) = e.from;
				que.emplace(_distance.at(e.to), e.to);
			}
		}
	}
}

long long Graph::distance(int to) const {
	if (to < 0 || V <= to) {
		throw out_of_range("[Graph::distance] index out of range");
	}
	return _distance.at(to);
}

int main() {
	int n;
	cin >> n;
	Graph G(n + 1);
	for (int i = 1; i <= n; i++) {
		int s;
		cin >> s;
		if (i < n) G.add_edge(i, i + 1, s);
		else G.add_edge(i, 1, s);
	}
	for (int i = 1; i <= n; i++) {
		int t;
		cin >> t;
		G.add_edge(0, i, t);
	}
	G.dijkstra(0);
	for (int i = 1; i <= n; i++) cout << G.distance(i) << endl;
}