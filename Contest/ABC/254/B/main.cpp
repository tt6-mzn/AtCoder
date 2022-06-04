#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<vector<int>> ans(n, vector<int>(n + 1));
	rep(i, n) {
		rep(j, i + 1) {
			if (j == 0 || j == i) ans[i][j] = 1;
			else ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
		}
	}
	rep(i, n) {
		cout << ans[i][0];
		for (int j = 1; j < i + 1; j++) {
			cout << " " << ans[i][j];
		}
		cout << endl;
	}
	return 0;
}