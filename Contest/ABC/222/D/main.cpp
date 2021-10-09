#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

void ss_v(vector<modint998244353> &a) {
	for (int i = a.size() - 2; i >= 0; i--) {
		a[i] = a[i] + a[i + 1];
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	if (n == 1) {
		cout << b[0] - a[0] + 1 << endl;
		return 0;
	}
	vector<modint998244353> ss(3010, 0);
	for (int i = b[n - 1]; i >= a[n - 1]; i--) ss[i] = 1;
	ss_v(ss);
	for (int i = n - 2; i >= 0; i--) {
		vector<modint998244353> ss_(3010, 0);
		for (int j = a[i]; j <= b[i]; j++) {
			ss_[j] = ss[j].val();
		}
		rep(j, 3010) ss[j] = ss_[j].val();
		ss_v(ss);
	}
	cout << ss[0].val() << endl;
}