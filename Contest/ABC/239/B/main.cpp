#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long x;
	cin >> x;
	if (x >= 0) {
		cout << x / 10 << endl;
	}
	else {
		cout << (-1) * ((abs(x) + 9) / 10) << endl;
	}
	return 0;
}