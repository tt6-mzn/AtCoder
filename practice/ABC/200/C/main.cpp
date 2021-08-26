#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) a[i] %= 200;
	vector<long long> memo(200, 0);
	rep(i, n) memo[a[i]]++;
	long long ans = 0;
	rep(i, 200) {
		ans += (memo[i] * (memo[i] - 1)) / 2;
	}
	cout << ans << endl;
}