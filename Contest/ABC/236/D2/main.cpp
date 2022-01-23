#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, ans = -1;
vector<vector<int>> a;
vector<bool> memo;

void rec(int cnt, int val) {
	if (cnt == n) {
		if (val > ans) ans = val;
		return;
	}
	int i = 0;
	while (memo[i]) i++;
	for (int j = i + 1; j < 2 * n; j++) {
		if (memo[j]) continue;
		memo[i] = true; memo[j] = true;
		rec(cnt + 1, val ^ a[i][j]);
		memo[i] = false; memo[j] = false;
	}
}

int main() {
	cin >> n;
	a.assign(2 * n, vector<int>(2 * n, 0));
	memo.assign(2 * n, false);
	rep(i, 2 * n) {
		for (int j = i; j < 2 * n; j++) {
			if (i != j) {
				cin >> a[i][j];
				a[j][i] = a[i][j];
			}
		}
	}

	rec(0, 0);
	cout << ans << endl;

	return 0;
}