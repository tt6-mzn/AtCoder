#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int l1, r1, l2, r2;
	cin >> l1 >> r1 >> l2 >> r2;
	int ans = 0;
	rep(i, 100) {
		if (l1 <= i && i < r1 && l2 <= i && i < r2) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}