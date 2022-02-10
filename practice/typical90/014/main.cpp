#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<long long> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	long long ans = 0;
	rep(i, n) ans += abs(a[i] - b[i]);
	cout << ans << endl;
	return 0;
}