#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, p, q;
	cin >> n >> p >> q;
	vector<int> d(n);
	rep(i, n) cin >> d[i];
	int ans = p;
	for (int di : d) {
		ans = min(ans, q + di);
	}
	cout << ans << endl;
	return 0;
}