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
	int ans = 0;
	rep(i, n) {
		if (a[a[i]] == i) ans++;
	}
	cout << ans / 2 << endl;
	return 0;
}