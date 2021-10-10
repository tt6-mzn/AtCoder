#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b;
	cin >> a >> b;
	for (int c = 0; c < 256; c++) {
		if ((a ^ c) == b) {
			cout << c << endl;
			return 0;
		}
	}
}