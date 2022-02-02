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
	long long s = 0, c;
	rep(i, n) s += a[i];
	c = s / 2;
	long long left = 0, i = 0;
	while (left + a[i] < c) left += a[i++];
	long long right = left + a[i];
	if (s & 1) cout << min(2 * (c - left) + 1, 2 * (right - c) - 1) << endl;
	else cout << min(2 * (c - left), 2 * (right - c)) << endl;
	return 0;
}