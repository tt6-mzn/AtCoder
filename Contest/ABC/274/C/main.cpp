#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> ans(2 * n + 2, 0);
	rep(i, n) {
		ans[2 * (i + 1)] = ans[a[i]] + 1;
		ans[2 * (i + 1) + 1] = ans[a[i]] + 1;
	}
	for (int i = 1; i <= 2 * n + 1; i++) cout << ans[i] << endl;
	return 0;
}