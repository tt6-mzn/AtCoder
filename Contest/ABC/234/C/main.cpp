#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long k;
	cin >> k;
	bool flg = false;
	for (int i = 63; i >= 0; i--) {
		if ((k >> i) & 1) {
			cout << 2;
			flg = true;
		}
		else {
			if (flg) cout << 0;
		}
	}
	cout << endl;
	return 0;
}