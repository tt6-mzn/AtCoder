#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long a, b, c; cin >> a >> b >> c;
	long long cb = 1;
	rep(_, b) cb *= c;
	if (a < cb) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}