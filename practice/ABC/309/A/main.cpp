#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b;
	cin >> a >> b;
	if (a % 3 == 1) {
		if (a + 1 == b) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	if (a % 3 == 2) {
		if (a - 1 == b|| a + 1 == b) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	if (a % 3 == 0) {
		if (a - 1 == b) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}