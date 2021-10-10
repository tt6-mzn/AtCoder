#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<double> l(n), r(n);
	rep(i, n) {
		int t;
		cin >> t >> l[i] >> r[i];
		if (t == 2) r[i] -= 0.5;
		else if (t == 3) l[i] += 0.5;
		else if (t == 4) {
			r[i] -= 0.5;
			l[i] += 0.5;
		}
	}
	int ans = 0;
	rep(i, n) {
		rep(j, i) {
			if (max(l[i], l[j]) <= min(r[i], r[j])) {
				ans++;
			}
		}
	}
	cout << ans << endl;
}