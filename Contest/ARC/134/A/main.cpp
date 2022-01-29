#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, l, w;
	cin >> n >> l >> w;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	vector<long long> b, c;
	b.push_back(0); c.push_back(a[0]);
	for (int i = 1; i < n; i++) {
		// a[i - 1]と重なっている場合
		if (a[i] <= a[i - 1] + w) continue;
		// a[i - 1]と重なっていない場合
		b.push_back(a[i - 1] + w); c.push_back(a[i]);
	}
	b.push_back(a[n - 1] + w); c.push_back(l);
	long long ans = 0;
	rep(i, b.size()) ans += (c[i] - b[i] + w - 1) / w;
	cout << ans << endl;
	return 0;
}