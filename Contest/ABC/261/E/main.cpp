#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, c;
	cin >> n >> c;
	vector<int> f(2);
	f[0] = 0;
	f[1] = ~0;
	rep(i, n) {
		int t, a;
		cin >> t >> a;
		rep(j, 2) {
			if (t == 1) f[j] &= a;
			if (t == 2) f[j] |= a;
			if (t == 3) f[j] ^= a;
		}
		c = (c & f[1]) | (~c & f[0]);
		cout << c << endl;
	}
}