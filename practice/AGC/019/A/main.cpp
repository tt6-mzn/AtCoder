#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long q, h, s, d;
	cin >> q >> h >> s >> d;
	long long n;
	cin >> n;
	s = min(s, 2 * min(h, 2 * q));
	long long a, b;
	a = n * s;
	b = (n / 2) * d + (n % 2) * s;
	cout << min(a, b) << endl;
	return 0;
}