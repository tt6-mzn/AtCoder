#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> a(n);
	rep(i, n) cin >> a[i];
	long long ans = -1;
	rep(i, n) rep(j, n) {
		for (int dx = -1; dx <= 1; dx++) {
			for (int dy = -1; dy <= 1; dy++) {
				if (dx == 0 && dy == 0) continue;
				int nx = i, ny = j;
				string s = "";
				rep(_, n) {
					s += a[nx][ny];
					nx = (nx + dx + n) % n;
					ny = (ny + dy + n) % n;
				}
				// cout << s << endl;
				ans = max(ans, stoll(s));
			}
		}
	}
	cout << ans << endl;
	return 0;
}