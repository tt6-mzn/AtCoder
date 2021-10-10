#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<long long> c(n);
	rep(i, n) cin >> c[i];
	sort(c.begin(), c.end());
	modint1000000007 ans = c[0];
	for (int i = 1; i < n; i++) {
		ans *= c[i] - i;
	}
	cout << ans.val() << endl;
}