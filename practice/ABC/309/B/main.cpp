#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	vector<string> b(n, string(n, '0'));
	
	for (int i = 1; i < n - 1; i++) {
		for (int j = 1; j < n - 1; j++) {
			b[i][j] = a[i][j];
		}
	}
	for (int j = 1; j < n; j++) b[0][j] = a[0][j - 1];
	for (int i = 1; i < n; i++) b[i][n - 1] = a[i - 1][n - 1];
	for (int j = 0; j < n - 1; j++) b[n - 1][j] = a[n - 1][j + 1];
	for (int i = 0; i < n - 1; i++) b[i][0] = a[i + 1][0];

	rep(i, n) cout << b[i] << endl;
	
	return 0;
}