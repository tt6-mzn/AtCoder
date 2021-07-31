#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(n), b(m);
	rep(i, n) cin >> a[i];
	rep(i, m) cin >> b[i];
	sort(b.begin(), b.end());
	int ans = 1100100100;
	rep(i, n) {
		auto position = lower_bound(b.begin(), b.end(), a[i]);
		int index = distance(b.begin(), position);
		if (index == 0) {
			ans = min(ans, abs(a[i] - b[index]));
		}
		else if (index == m) {
			ans = min(ans, abs(a[i] - b[index - 1]));
		}
		else {
			ans = min(ans, abs(a[i] - b[index]));
			ans = min(ans, abs(a[i] - b[index - 1]));
		}
	}
	cout << ans << endl;
}