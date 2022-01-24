#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long a, b, c, k;
	cin >> a >> b >> c >> k;
	if (k & 1) cout << b - a << endl;
	else cout << a - b << endl;
	return 0;
}