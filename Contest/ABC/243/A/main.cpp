#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int v, a, b, c;
	cin >> v >> a >> b >> c;
	while (1) {
		v -= a;
		if (v < 0) {
			cout << "F" << endl;
			return 0;
		}
		v -= b;
		if (v < 0) {
			cout << "M" << endl;
			return 0;
		}
		v -= c;
		if (v < 0) {
			cout << "T" << endl;
			return 0;
		}
	}
	return 0;
}