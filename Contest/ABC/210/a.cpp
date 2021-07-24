#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, a, x, y;
	cin >> n >> a >> x >> y;
	int ans = 0;
	rep(i, n) {
		if (i < a) ans += x;
		else ans += y;
	}
	cout << ans << endl;
}