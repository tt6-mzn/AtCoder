#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> x(n), c(n);
	rep(i, n) cin >> x[i];
	rep(i, n) x[i]--;
	rep(i, n) cin >> c[i];
	dsu uf(n);
	long long ans = 0;
	rep(i, n) {
		if (uf.same(i, x[i]) == false) {
			uf.merge(i, x[i]);
		}
		else {
			int j = x[i];
			long long cmin = min(c[i], c[j]);
			while (j != i) {
				cmin = min(cmin, (long long)c[j]);
				j = x[j];
			}
			ans += cmin;
		}
	}
	cout << ans << endl;
	return 0;
}