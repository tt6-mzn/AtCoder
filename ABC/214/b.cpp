#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int s, t;
	cin >> s >> t;
	int ans = 0;
	rep(a, s + 1) {
		rep(b, s + 1) {
			rep(c, s + 1) {
				if (a + b + c <= s && a * b * c <= t) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}