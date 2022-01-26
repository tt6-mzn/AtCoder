#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	long long a, b;
	cin >> a >> b;
	if ((b - a) % 2 == 0) {
		cout << (b - a) / 2 << endl;
		return 0;
	}
	if ((a - 1) <= (n - b)) {
		cout << (a - 1) + 1 + (b - a) / 2 << endl;
	}
	else {
		cout << (n - b) + 1 + (b - a) / 2 << endl;
	}
	return 0;
}