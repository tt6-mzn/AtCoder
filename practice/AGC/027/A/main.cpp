#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	sort(a.begin(), a.end());
	int now = 0;
	while (now < n && x - a[now] >= 0) {
		x -= a[now];
		now++;
	}
	if (x == 0) {
		cout << now << endl;
	}
	else if (now < n) {
		cout << now << endl;
	}
	else {
		cout << now - 1 << endl;
	}
	return 0;
}