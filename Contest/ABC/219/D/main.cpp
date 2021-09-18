#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	int x, y;
	cin >> x >> y;
	vector<int> a(n), b(n);
	rep(i, n) {
		cin >> a[i];
		cin >> b[i];
	}

	vector<vector<vector<int>>> dp(n, vector<vector<int>>(x + 1, vector<int>(y + 1, 1100100)));
	rep(i, n) {
		rep(j, min(x + 1, a[i] + 1)) {
			rep(k, min(y + 1, b[i] + 1)) {
				dp[i][j][k] = 1;
			}
		}
		dp[i][0][0] = 0;
	}
	
	rep(i, n) {
		rep(j, x + 1) {
			rep(k, y + 1) {
				if (0 <= i - 1) {
					dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j][k]);
					if (0 <= j - a[i] && 0 <= k - b[i]) {
						dp[i][j][k] = min(dp[i][j][k], dp[i - 1][j - a[i]][k - b[i]] + 1);
					}
				}
			}
		}
	}

	if (dp[n - 1][x][y] >= 1100100) {
		cout << -1 << endl;
	}
	else {
		cout << dp[n - 1][x][y] << endl;
	}
}