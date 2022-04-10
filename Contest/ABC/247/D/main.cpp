#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int q;
	cin >> q;
	queue<long long> qx, qc; // (x, c) := xがc個ある
	rep(_, q) {
		int n;
		cin >> n;
		if (n == 1) {
			long long x, c;
			cin >> x >> c;
			qx.push(x);
			qc.push(c);
		}
		if (n == 2) {
			long long c;
			cin >> c; // c個取り出す
			long long ans = 0;
			while (c > 0) {
				if (qc.front() <= c) {
					c -= qc.front();
					ans += qx.front() * qc.front();
					qx.pop();
					qc.pop();
				}
				else {
					qc.front() -= c;
					ans += c * qx.front();
					c = 0;
				}
			}
			cout << ans << endl;
		}
	}
	return 0;
}