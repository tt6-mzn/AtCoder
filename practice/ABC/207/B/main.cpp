#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b >= c * d) {
		cout << -1 << endl;
		return 0;
	}
	long long n = 0;
	while (a + n * b > d * n * c) n++;
	cout << n << endl;
}