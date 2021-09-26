#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int f(int a, int b) {
	return (a + b) % 10;
}

int g(int a, int b) {
	return (a * b) % 10;
}

int main() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	long long mod = 998244353;
	vector<vector<long long>> dp(10, vector<long long>(n, 0));
	dp[a[0]][0] = 1;
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < 10; k++) {
			int fk = f(k, a[i]);
			int gk = g(k, a[i]);
			dp[fk][i] = (dp[fk][i] + dp[k][i - 1]) % mod;
			dp[gk][i] = (dp[gk][i] + dp[k][i - 1]) % mod;
		}
	}
	rep(i, 10) {
		cout << dp[i][n - 1] << endl;
	}
}