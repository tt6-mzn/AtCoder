#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	vector<long long> a(n), last_q(n, -1);
	rep(i, n) cin >> a[i];
	long long q;
	cin >> q;
	long long qq = -2, x = 0;

	rep(i, q) {
		long long op;
		cin >> op;
		if (op == 1) {
			long long xq;
			cin >> xq;
			qq = i;
			x = xq;
		}
		if (op == 2) {
			long long iq, xq;
			cin >> iq >> xq; iq--;
			if (qq > last_q[iq]) {
				a[iq] = x;
				a[iq] += xq;
				last_q[iq] = i;
			}
			else {
				a[iq] += xq;
				last_q[iq] = i;
			}
		}
		if (op == 3) {
			long long iq;
			cin >> iq; iq--;
			if (qq > last_q[iq]) cout << x << endl;
			else cout << a[iq] << endl;
		}
	}
	return 0;
}