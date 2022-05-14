#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, w;
	cin >> n >> w;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<bool> memo(w + 1, false);
	rep(i, n) {
		if (a[i] <= w) memo[a[i]] = true;
	}
	rep(i, n) rep(j, i) {
		if (a[i] + a[j] <= w) memo[a[i] + a[j]] = true;
	}
	rep(i, n) rep(j, i) rep(k, j) {
		if (a[i] + a[j] + a[k] <= w) memo[a[i] + a[j] + a[k]] = true;
	}
	int ans = 0;
	rep(i, w + 1) {
		if (memo[i]) ans++;
	}
	cout << ans << endl;
	return 0;
}