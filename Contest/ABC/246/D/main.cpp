#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	long long x = 1100100100100100100LL;
	for (long long a = 0; a < 1000100; a++) {
		long long b = 0;
		if (a * a * a < n) {
			long long left = 0, right = 1000100;
			while (right - left > 1) {
				long long mid = (left + right) / 2;
				if ((a * a + mid * mid) * (a + mid) >= n) right = mid;
				else left = mid;
			}
			b = right;
		}
		x = min(x, (a * a + b * b) * (a + b));
	}
	cout << x << endl;
	return 0;
}