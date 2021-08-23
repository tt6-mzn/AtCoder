#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	int amax, bmin;
	amax = a[0];
	for (int i = 1; i < n; i++) amax = max(a[i], amax);
	bmin = b[0];
	for (int i = 1; i < n; i++) bmin = min(b[i], bmin);
	cout << max(0, bmin - amax + 1) << endl;
}