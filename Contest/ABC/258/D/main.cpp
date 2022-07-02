#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, x;
	cin >> n >> x;
	vector<long long> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	vector<long long> dp(n, 0);
	long long s = a[0] + b[0];
	long long minB = b[0];
	dp[0] = a[0] + x * b[0];
	for (int i = 1; i < n; i++) {
		s += a[i] + b[i];
		minB = min(minB, b[i]);
		dp[i] = min(dp[i - 1], s + (x - (i + 1)) * minB);
	}
	cout << dp[n - 1] << endl;
	return 0;
}