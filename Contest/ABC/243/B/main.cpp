#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	int ans1 = 0, ans2 = 0;
	rep(i, n) if (a[i] == b[i]) ans1++;
	rep(i, n) {
		rep(j, n) {
			if (i == j) continue;
			if (a[i] == b[j]) ans2++;
		}
	}
	cout << ans1 << endl;
	cout << ans2 << endl;
	return 0;
}