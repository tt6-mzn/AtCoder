#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m, x, t, d;
	cin >> n >> m >> x >> t >> d;
	if (x <= m && m < n) {
		cout << t << endl;
		return 0;
	}
	cout << t - d * (x - m) << endl;
	return 0;
}