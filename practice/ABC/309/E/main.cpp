#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> p(n + 1);
	for (int i = 2; i <= n; i++) cin >> p[i];
	vector<int> x(m), y(m);
	rep(i, m) cin >> x[i] >> y[i];

	vector<int> dp(n + 1, -1);
	rep(i, m) {
		dp[x[i]] = max(dp[x[i]], y[i]);
	}
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i], dp[p[i]] - 1);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] >= 0) ans++;
	}
	cout << ans << endl;
}