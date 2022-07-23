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
	rep(i, n) rep(j, n) {
		if (i == j) continue;
		if (a[i][j] == 'W' && a[j][i] != 'L') {
			cout << "incorrect" << endl;
			return 0;
		}
		if (a[i][j] == 'L' && a[j][i] != 'W') {
			cout << "incorrect" << endl;
			return 0;
		}
		if (a[i][j] == 'D' && a[j][i] != 'D') {
			cout << "incorrect" << endl;
			return 0;
		}
	}
	cout << "correct" << endl;
	return 0;
}