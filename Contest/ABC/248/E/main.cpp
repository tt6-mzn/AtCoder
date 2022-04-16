#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	if (m == 1) {
		cout << "Infinity" << endl;
		return 0;
	}
	vector<long long> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	long long ans = 0;
	vector<vector<bool>> memo(n, vector<bool>(n, false));
	rep(j, n) rep(i, j) {
		if (memo[i][j]) continue;
		memo[i][j] = true;
		memo[j][i] = true;
		long long cnt = 0;
		rep(k, n) {
			if ((y[k] - y[i]) * (x[i] - x[j]) == (y[i] - y[j]) * (x[k] - x[i])) {
				memo[i][k] = true;
				memo[k][i] = true;
				memo[j][k] = true;
				memo[k][j] = true;
				cnt++;
			}
		}
		if (cnt >= m) ans++;
	}
	cout << ans << endl;
	return 0;
}