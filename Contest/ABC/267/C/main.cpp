#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m; cin >> n >> m;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	long long ans = 0, ss = 0;
	rep(i, m) {
		ans += a[i] * (i + 1);
		if (i != 0) ss += a[i];
	}
	long long ans_ = ans;
	for (int i = 1; i < n - m + 1; i++) {
		ans_ -= a[i - 1];
		ans_ -= ss;
		ans_ += a[i + m - 1] * m;
		// cout << ans_ << " " << ss << endl;
		ans = max(ans, ans_);
		ss -= a[i];
		ss += a[i + m - 1];
	}
	cout << ans << endl;
	return 0;
}