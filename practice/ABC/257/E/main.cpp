#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> c(9);
	rep(i, 9) cin >> c[i];
	int minc = 1100100100;
	rep(i, 9) minc = min(minc, c[i]);
	int d = n / minc;
	string ans = "";
	while (d > 0) {
		for (int i = 8; i >= 0; i--) {
			// cout << n - c[i] << endl;
			if (n - c[i] >= 0 && (n - c[i]) / minc >= d - 1) {
				ans += to_string(i + 1);
				n = max(0, n - c[i]);
				break;
			}
		}
		d--;
	}
	cout << ans << endl;
	return 0;
}