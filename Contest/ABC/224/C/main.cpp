#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<long long> x(n), y(n);
	rep(i, n) cin >> x[i] >> y[i];
	long long ans = 0;
	rep(i, n) {
		rep(j, i) {
			rep(k, j) {
				long long a, b, c, d;
				a = x[j] - x[i];
				b = y[j] - y[i];
				c = x[k] - x[i];
				d = y[k] - y[i];
				if (b * c != a * d) ans++;
			}
		}
	}
	cout << ans << endl;
}