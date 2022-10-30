#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> c(h);
	rep(i, h) cin >> c[i];
	vector<int> ans(w, 0);
	rep(j, w) {
		rep(i, h) if (c[i][j] == '#') ans[j]++;
	}
	cout << ans[0];
	for (int i = 1; i < w; i++) cout << " " << ans[i];
	cout << endl;
	return 0;
}