#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long x, a, d, n;
	cin >> x >> a >> d >> n;
	if (d < 0) {
		x = -x;
		a = -a;
		d = -d;
	}
	long long last = a + (n - 1) * d;
	if (x <= a) {
		cout << a - x << endl;
		return 0;
	}
	if (last <= x) {
		cout << x - last << endl;
		return 0;
	}
	long long k = (x - a) / d;
	long long left = a + k * d;
	long long right = a + (k + 1) * d;
	cout << min(x - left, right - x) << endl;
	return 0;
}