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
	map<int, vector<pair<int, int>>> ps;
	CC<int> w_cc;
	rep(_, n) {
		vector<int> hwd(3);
		rep(i, 3) cin >> hwd[i];
		sort(hwd.begin(), hwd.end());
		ps[hwd[0]].emplace_back(hwd[1], hwd[2]);
		w_cc.add(hwd[1]);
	}

	segtree<int, op, e> st(w_cc.size());
	for (auto [h, wd] : ps) {
		for (auto [w, d] : wd) {
			w = w_cc(w);
			if (st.prod(0, w) < d) {
				cout << "Yes" << endl;
				return 0;
			}
		}
		for (auto [w, d] : wd) {
			st.set(w, op(d, st.get(w)));
		}
	}
	cout << "No" << endl;
	return 0;
}