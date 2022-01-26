#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int x;
	cin >> x;
	vector<int> items = {100, 101, 102, 103, 104, 105};
	vector<vector<bool>> dp(6 + 1, vector<bool>(x + 1, false));
	// dp[i][j] := i未満のコインの中から個数制限なしでxにできるか
	rep(i, 7) dp[i][0] = true;
	// for (int j = 1; j < x + 1; j++) dp[0][j] = false;
	// dp[6][x]を求める
	for (int i = 1; i < 7; i++) {
		for (int j = 1; j < x + 1; j++) {
			if (dp[i - 1][j]) dp[i][j] = true;
			if (j - items[i - 1] >= 0) {
				if (dp[i - 1][j - items[i - 1]]) dp[i][j] = true;
				if (dp[i][j - items[i - 1]]) dp[i][j] = true;
			}
		}
	}
	if (dp[6][x]) cout << 1 << endl;
	else cout << 0 << endl;
	return 0;
}