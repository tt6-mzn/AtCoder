#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long a, b, c;
	cin >> a >> b >> c;
	if ((a & 1) && (b & 1) && (c & 1)) {
		cout << min(a * b, min(b * c, c * a)) << endl;
		return 0;
	}
	cout << 0 << endl;
	return 0;
}