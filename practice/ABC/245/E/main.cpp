#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool comp(const tuple<int, int, int>& left, const tuple<int, int, int>& right) {
	int l0, l1, l2, r0, r1, r2;
	tie(l0, l1, l2) = left;
	tie(r0, r1, r2) = right;
	if (l0 != r0) return l0 > r0; // 縦の長さ
	if (l2 != r2) return l2 > r2; // 箱を優先
	return l1 > r1; // 横の長さ
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(n), c(m), d(m);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	rep(j, m) cin >> c[j];
	rep(j, m) cin >> d[j];
	vector<tuple<int, int, int>> p(n + m);
	rep(i, n) p[i] = make_tuple(a[i], b[i], 0); // チョコ
	rep(j, m) p[n + j] = make_tuple(c[j], d[j], 1); // 箱
	sort(p.begin(), p.end(), comp);

	// rep(i, n + m) {
	// 	int a, b, t; tie(a, b, t) = p[i];
	// 	cout << a << " ";
	// 	cout << b << " ";
	// 	cout << t << endl;
	// }
	// return 0;

	multiset<int> ms;
	rep(i, n + m) {
		int a, b, t; tie(a, b, t) = p[i];
		if (t == 0) {
			auto it = ms.lower_bound(b);
			if (it == ms.end()) {
				cout << "No" << endl;
				return 0;
			}
			ms.erase(it);
		}
		if (t == 1) ms.insert(b);
	}
	cout << "Yes" << endl;
	return 0;
}