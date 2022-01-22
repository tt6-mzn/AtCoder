#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long a, b;
	cin >> a >> b;
	if (a * b <= 0) {
		cout << "Zero" << endl;
		return 0;
	}
	if (a > 0) {
		cout << "Positive" << endl;
		return 0;
	}
	if ((b - a + 1) & 1) {
		cout << "Negative" << endl;
		return 0;
	}
	cout << "Positive" << endl;
	return 0;
}