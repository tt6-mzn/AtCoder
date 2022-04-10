#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, x, y;
	cin >> n >> x >> y;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	long long l = 0, r = 0;
	long long ans = 0;
	long long pre = 0;
	while (l < n) {
		while (r < n && y <= a[r] && a[r] <= x) r++;
		long long ind_x = -1, ind_y = -1;
		for (int i = l; i < r; i++) {
			if (a[i] == x) {
				if (ind_y != -1) {
					ans += ind_y - l + 1;
					pre = ind_y - l + 1;
				}
			}
			else if (a[i] == y) {
				if (ind_x != -1) {
					ans += ind_x - l + 1;
					pre = ind_x - l + 1;
				}
			}
			else ans += pre;
			if (a[i] == x) ind_x = i;
			if (a[i] == y) ind_y = i;
		}
		l = r + 1;
		r = l;
	}
	if (x == y) {
		rep(i, n) if (a[i] == x) ans++;
	}
	cout << ans << endl;
	return 0;
}