#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m), d(m);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(i, m) cin >> c[i];
	rep(i, m) cin >> d[i];
	vector<tuple<int, int, int>> p;
	rep(i, n) p.emplace_back(a[i], 0, b[i]); // チョコ
	rep(i, m) p.emplace_back(c[i], 1, d[i]); // 箱
	sort(p.begin(), p.end(), greater<tuple<int, int, int>>());

	// rep(i, n + m) {
	// 	int a, t, b
	// 	tie(a, t, b) = p[i];
	// 	cout << a << " ";
	// 	cout << b << " ";
	// 	cout << t << endl;
	// }
	
	multiset<int> mset;
	rep(i, n + m) {
		int a, t, b;
		tie(a, t, b) = p[i];

		// cout << a << " ";
		// cout << b << " ";
		// cout << t << endl;

		if (t == 1) {
			mset.insert(b);
		}
		if (t == 0) {
			auto it = mset.lower_bound(b);
			if (it == mset.end()) {
				cout << "No" << endl;
				return 0;
			}
			mset.erase(*it);
		}
	}
	cout << "Yes" << endl;
	return 0;
}