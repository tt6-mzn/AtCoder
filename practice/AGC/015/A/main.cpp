#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// 和が最小: A, A, ..., A, B -> (N - 1)A + B
// 和が最大: A, B, B, ..., B -> A + (N - 1)B

int main() {
	long long n, a, b;
	cin >> n >> a >> b;
	if (a > b) {
		cout << 0 << endl;
		return 0;
	}
	if (n == 1) {
		if (a == b) cout << 1 << endl;
		else cout << 0 << endl;
		return 0;
	}
	long long smin = (n - 1) * a + b;
	long long smax = a + (n - 1) * b;
	cout << smax - smin + 1 << endl;
	return 0;
}