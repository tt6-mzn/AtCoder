#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

const long long INF = 1LL << 62;

class Edge {
public:
	int to; // 辺の終点
	long long cost = 1; // 辺の重み
	Edge() {};
	Edge(int to) : to(to) {};
	Edge(int to, long long cost) : to(to), cost(cost) {};
};

class Dijkstra {
private:
	vector<vector<Edge>> _Graph; // _Graph[i]:=頂点iから出る辺
	vector<long long> _distance; // dijkstra()の結果が格納される
	vector<int> _prev; // dijkstra()の結果が格納される
public:
	int V; // 頂点数
	int E = 0; // 辺数
	Dijkstra(int V); // コンストラクタ
	void add_edge(int from, int to); // 辺の追加
	void add_edge(int from, int to, long long cost); // 辺の追加(重みあり)
	void dijkstra(int s); // ダイクストラ法
	long long distance(int to) const; // ダイクストラ法の結果から頂点toまでの最短距離を返す
	vector<int> path(int to) const; // ダイクストラ法の結果から頂点toまでのルートを返す
};

/* 頂点数と辺の数を指定して初期化 */
Dijkstra::Dijkstra(int V) : V(V) {
	_Graph.resize(V);
}

void Dijkstra::add_edge(int from, int to) {
	if (from < 0 || V <= from) {
		throw out_of_range("[Graph::add_edge] index out of range");
		exit(0);
	}
	if (to < 0 || V <= to) {
		throw out_of_range("[Graph::add_edge] index out of range");
		exit(0);
	}
	Edge tmp(to);
	_Graph.at(from).push_back(tmp);
	E++;
}

void Dijkstra::add_edge(int from, int to, long long cost) {
	if (from < 0 || V <= from) {
		throw out_of_range("[Graph::add_edge] index out of range");
		exit(0);
	}
	if (to < 0 || V <= to) {
		throw out_of_range("[Graph::add_edge] index out of range");
		exit(0);
	}
	Edge tmp(to, cost);
	_Graph.at(from).push_back(tmp);
	E++;
}

/* ダイクストラ法で頂点sから各頂点への最短距離を求める
 * 計算量はO(ElogV)
 * 返り値: 各頂点への最短距離が入った配列
*/
void Dijkstra::dijkstra(int s) {
	_distance.assign(V, INF);
	_prev.assign(V, -1);
	priority_queue<
		tuple<long long, int, int>,
		vector<tuple<long long, int, int>>,
		greater<tuple<long long, int, int>>> que;
	que.emplace(0, -1, s);
	while (!que.empty()) {
		long long d; int pre, v;
		tie(d, pre, v) = que.top(); que.pop();
		if (_distance[v] != INF) continue;
		_distance[v] = d;
		_prev[v] = pre;
		for (const Edge& next : _Graph[v]) {
			que.emplace(d + next.cost, v, next.to);
		}
	}
}

/* dijkstra実行後にのみ使用可能
 * 頂点toまでの最短距離を返す
*/
long long Dijkstra::distance(int to) const {
	if (_distance.size() == 0 || to < 0 || V <= to) {
		throw out_of_range("[Graph::distance] index out of range");
		exit(0);
	}
	return _distance.at(to);
}

/* dijkstra実行後にのみ使用可能
 * 頂点toまでの最短経路の一つを復元する
 * 始点の頂点は返り値に含まれない
*/
vector<int> Dijkstra::path(int to) const {
	if (_distance.size() == 0 || to < 0 || V <= to) {
		throw out_of_range("[Graph::path] index out of range");
		exit(0);
	}
	vector<int> ret;
	while (_prev.at(to) != -1) {
		ret.push_back(to);
		to = _prev.at(to);
	}
	reverse(ret.begin(), ret.end());
	return ret;
}