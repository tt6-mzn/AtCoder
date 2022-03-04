#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	long long A = 1;
	long long ans = 0;
	while (A * A <= 2 * n) {
		if ((2 * n) % A == 0) {
			long long B = (2 * n) / A;
			if ((A + B - 1) % 2 == 0 && (A - B + 1) % 2 == 0) ans += 2;
		}
		A++;
	}
	cout << ans << endl;
	return 0;
}