#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ans = 0;
	rep(i, n) ans += max(0, a[i] - 10);
	cout << ans << endl;
}