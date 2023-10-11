#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	for (int i = 1; i <= n; i++) {
		auto it = lower_bound(a.begin(), a.end(), i);
		cout << *it - i << endl;
	}
	return 0;
}