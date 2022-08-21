#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w;
	cin >> h >> w;
	vector<string> g(h);
	rep(i, h) cin >> g[i];
	vector<vector<bool>> memo(h, vector<bool>(w, false));
	int i = 0, j = 0;
	while (memo[i][j] == false) {
		memo[i][j] = true;
		if (g[i][j] == 'U' && i - 1 >= 0) {
			i--;
			continue;
		}
		if (g[i][j] == 'D' && i + 1 < h) {
			i++;
			continue;
		}
		if (g[i][j] == 'L' && j - 1 >= 0) {
			j--;
			continue;
		}
		if (g[i][j] == 'R' && j + 1 < w) {
			j++;
			continue;
		}
		cout << i + 1 << " " << j + 1 << endl;
		return 0;
	}
	cout << -1 << endl;
	return 0;
}