#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, m;
	cin >> n >> m;
	vector<long long> a(n + m + 1, 0), c(n + m + 1, 0);
	rep(i, n + 1) cin >> a[i];
	rep(i, n + m + 1) cin >> c[i];
	vector<long long> b(n + m + 1, 0);
	long long start = 0;
	while (a[start] == 0) start++;
	rep(i, m + 1) {
		b[i] = c[start + i];
		for (int j = 0; j <= start + i; j++) {
			if (j == start) continue;
			b[i] -= a[j] * b[start + i - j];
		}
		// for (int j = 1; j <= start + i; j++) b[i] -= a[j] * b[start + i - j];
		b[i] /= a[start];
	}
	cout << b[0];
	for (int i = 1; i < m + 1; i++) cout << " " << b[i];
	cout << endl;
	return 0;
}