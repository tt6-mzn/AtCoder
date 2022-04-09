#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	long long a, b, c;
	cin >> a >> b >> c;
	long long ans = 10000;
	for (long long i = 0; i < 10000; i++) {
		for (long long j = 0; j < 10000 - i; j++) {
			if (a * i + b * j > n) continue;
			if ((n - a * i - b * j) % c != 0) continue;
			long long k = (n - a * i - b * j) / c;
			ans = min(ans, i + j + k);
		}
	}
	cout << ans << endl;
}