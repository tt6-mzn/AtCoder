#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long a, b, k;
	cin >> a >> b >> k;
	int ans = 0;
	while (a < b) {
		a *= k;
		ans++;
	}
	cout << ans << endl;
	return 0;
}