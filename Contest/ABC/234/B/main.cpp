#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	int xx, yy, dd = -1;
	rep(j, n) {
		rep(i, j) {
			int tmp = (x[i] - x[j]) * (x[i] - x[j]);
			tmp += (y[i] - y[j]) * (y[i] - y[j]);
			dd = max(dd, tmp);
		}
	}
	printf("%.10lf\n", sqrt(dd));
	return 0;
}