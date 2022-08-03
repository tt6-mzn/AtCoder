#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, n) a[i]--;
	int cnt = 0;
	rep(i, n) if (i == a[i]) cnt++;
	long long ans = 0;
	rep(i, n) {
		if (i < a[i]) {
			if (a[a[i]] == i) ans++;
		}
		if (i == a[i]) {
			ans += cnt - 1;
			cnt--;
		}
	}
	cout << ans << endl;
	return 0;
}