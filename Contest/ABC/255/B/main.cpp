#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long dist(long long x1, long long y1, long long x2, long long y2) {
	return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
	long long n, k;
	cin >> n >> k;
	set<long long> a;
	vector<long long> x(n), y(n);
	rep(i, k) {
		long long t; cin >> t;
		t--;
		a.insert(t);
	}
	rep(i, n) cin >> x[i] >> y[i];
	long long ans = -1;
	rep(i, n) {
		// iを覆うために必要な光の最小値
		long long d = 1LL << 62;
		rep(j, n) {
			if (a.find(j) != a.end()) {
				d = min(d, dist(x[i], y[i], x[j], y[j]));
			}
		}
		ans = max(ans, d);
	}
	printf("%.10lf\n", sqrt(ans));
	// cout << sqrt(ans) << endl;
	return 0;
}