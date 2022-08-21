#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, m, t;
	cin >> n >> m >> t;
	vector<long long> a(n, 0), b(n, 0);
	rep(i, n - 1) cin >> a[i];
	rep(i, m) {
		long long x, y;
		cin >> x >> y;
		b[x - 1] = y;
	}
	int now = 0;
	while (now < n) {
		t += b[now];
		t -= a[now];
		if (t <= 0) {
			cout << "No" << endl;
			return 0;
		}
		now++;
	}
	cout << "Yes" << endl;
	return 0;
}