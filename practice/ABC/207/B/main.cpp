#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (b >= c) {
		cout << -1 << endl;
		return 0;
	}
	int n = 0;
	while (a + n * b > d * n * c) n++;
	cout << n << endl;
}