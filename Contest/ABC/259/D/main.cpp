#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long ds(long long x1, long long y1, long long x2, long long y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	long long n;
	cin >> n;
	long long sx, sy, tx, ty;
	cin >> sx >> sy >> tx >> ty;
	vector<long long> x(n), y(n), r(n);
	rep(i, n) cin >> x[i] >> y[i] >> r[i];
	dsu uf(n);
	long long si, ti;
	rep(i, n) {
		if (ds(sx, sy, x[i], y[i]) == r[i] * r[i]) si = i;
		if (ds(tx, ty, x[i], y[i]) == r[i] * r[i]) ti = i;
	}
	rep(i, n) rep(j, n) {
		if (i == j) continue;
		long long d2 = ds(x[i], y[i], x[j], y[j]);
		long long r1 = r[i];
		long long r2 = r[j];
		if (r1 < r2) swap(r1, r2);
		if (d2 > (r1 + r2) * (r1 + r2)) continue;
		if (d2 < (r1 - r2) * (r1 - r2)) continue;
		uf.merge(i, j);
		// else if (d2 < r[i] * r[i]) {
		// 	// jがiの内部にある

		// }
	}
	if (uf.same(si, ti)) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}