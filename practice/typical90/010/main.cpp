#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> c(n), p(n);
	rep(i, n) cin >> c[i] >> p[i];

	vector<int> a(n + 1), b(n + 1);
	a[0] = 0; b[0] = 0;
	for (int i = 1; i < n + 1; i++) {
		if (c[i - 1] == 1) {
			a[i] = a[i - 1] + p[i - 1];
			b[i] = b[i - 1];
		}
		else {
			a[i] = a[i - 1];
			b[i] = b[i - 1] + p[i - 1];
		}
	}
	
	int q;
	cin >> q;
	rep(i, q) {
		long long l, r;
		cin >> l >> r;
		l--; r--;
		cout << a[r + 1] - a[l] << " ";
		cout << b[r + 1] - b[l] << endl;
	}
	return 0;
}