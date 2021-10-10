#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<long long> c(n);
	rep(i, n) cin >> c[i];
	sort(c.begin(), c.end());
	long long ans = c[0];
	long long mod = 1000000000 + 7;
	for (int i = 1; i < n; i++) {
		ans = (ans * (c[i] - i)) % mod;
	}
	cout << ans << endl;
}