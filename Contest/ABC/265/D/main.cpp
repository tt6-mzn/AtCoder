#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long n, p, q, r;
vector<long long> a;
vector<long long> sa;

int nibu(long long x, long long sum) {
	long long l = x, r = n + 1;
	while (r - l > 1) {
		long long mid = (l + r) / 2;
		if (sa[mid] - sa[x] > sum) {
			r = mid;
		}
		else {
			l = mid;
		}
	}
	if (sa[l] - sa[x] == sum) return l;
	return -1;
}

int main() {
	cin >> n >> p >> q >> r;
	a.assign(n, 0);
	rep(i, n) cin >> a[i];
	sa.assign(n + 2, 0);
	rep(i, n) sa[i + 1] = a[i] + sa[i];
	sa[n + 1] = 1100100100100100100LL;

	// cout << nibu(1, p) << endl;
	// return 0;

	rep(x, n) {
		int y = nibu(x, p);
		if (y == -1) continue;
		int z = nibu(y, q);
		if (z == -1) continue;
		int w = nibu(z, r);
		if (w == -1) continue;
		cout << "Yes" << endl;
		return 0;
	}

	cout << "No" << endl;
	return 0;
}