#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	for (int i = a; i <= b; i++) {
		if (i % c == 0) {
			cout << i << endl;
			return 0;
		}
	}
	cout << -1 << endl;
}