#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b;
	cin >> a >> b;
	if (abs(a - b) == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	if (a == 10 && b == 1) {
		cout << "Yes" << endl;
		return 0;
	}
	if (a == 1 && b == 10) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}