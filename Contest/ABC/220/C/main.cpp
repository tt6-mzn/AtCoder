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
	long long x;
	cin >> x;
	long long s = 0;
	rep(i, n) s += a[i];
	
	long long ans = n * (x / s);
	x = x - (s * (x / s));
	int i = 0;
	while (x >= 0) {
		x -= a[i];
		ans++;
		i++;
	}
	cout << ans << endl;
}