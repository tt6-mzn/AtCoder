#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	int r, c;
	cin >> r >> c;
	int ans = 0;
	if (1 <= r - 1) ans++;
	if (r + 1 <= h) ans++;
	if (1 <= c - 1) ans++;
	if (c + 1 <= w) ans++;
	cout << ans << endl;
	return 0;
}