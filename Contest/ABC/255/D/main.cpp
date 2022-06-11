#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, q;
	cin >> n >> q;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	vector<long long> sa(n + 1);
	sa[0] = 0;
	for (int i = 1; i < n + 1; i++) sa[i] = sa[i - 1] + a[i - 1];

	rep(_, q) {
		long long x;
		cin >> x;
		auto it = lower_bound(a.begin(), a.end(), x);
		long long ans = 0;
		ans = (it - a.begin()) * x;
		ans -= sa[it - a.begin()];
		ans += sa[n] - sa[it - a.begin()];
		ans -= (a.end() - it) * x;
		cout << ans << endl;
	}
	return 0;
}