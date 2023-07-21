#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// coodinate compression
template<typename T=int>
struct CC {
	bool initialized;
	vector<T> xs;
	CC(): initialized(false) {}
	void add(T x) { xs.push_back(x); }
	void init() {
		sort(xs.begin(), xs.end());
		xs.erase(unique(xs.begin(), xs.end()), xs.end());
		initialized = true;
	}
	int operator()(T x) {
		if (!initialized) init();
		return upper_bound(xs.begin(), xs.end(), x) - xs.begin() - 1;
	}
	T operator[](int i) {
		if (!initialized) init();
		return xs[i];
	}
	int size() {
		if (!initialized) init();
		return xs.size();
	}
};

const int inf = 1100100100;
int op(int a, int b) { return min(a, b); }
int e() { return inf; }

int main() {
	int n;
	cin >> n;
	map<int, vector<pair<int, int>>> hwd;
	CC w_cc;
	rep(_, n) {
		vector<int> hwd_(3);
		rep(i, 3) cin >> hwd_[i];
		sort(hwd_.begin(), hwd_.end());
		hwd[hwd_[0]].emplace_back(hwd_[1], hwd_[2]);
		w_cc.add(hwd_[1]);
	}

	segtree<int, op, e> tree(w_cc.size());

	for (auto [h, wd] : hwd) {
		for (auto [w, d] : wd) {
			w = w_cc(w);
			if (tree.prod(0, w) < d) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		for (auto [w, d] : wd) {
			w = w_cc(w);
			tree.set(w, op(d, tree.get(w)));
		}
	}
	cout << "No" << endl;
	return 0;
}