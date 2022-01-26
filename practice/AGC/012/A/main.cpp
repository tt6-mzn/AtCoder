#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<long long> a(3 * n);
	rep(i, 3 * n) cin >> a[i];
	sort(a.begin(), a.end());
	int now = 3 * n - 2;
	long long ans = 0;
	rep(i, n) {
		ans += a[now];
		now -= 2;
	}
	cout << ans << endl;
	return 0;
}