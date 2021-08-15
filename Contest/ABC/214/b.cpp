#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long s, t;
	cin >> s >> t;
	long long ans = 0;
	rep(i, s + 1) {
		rep(j, s + 1) {
			rep(k, s + 1) {
				if (i + j + k <= s && i * j * k <= t) {
					ans++;
				}
			}
		}
	}
	cout << ans << endl;
}