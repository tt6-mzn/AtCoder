#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;


/*
dp[i][v] = i未満の案の中から選んでパラメータがv以上となるように
		   するときに必要なコストの最小値
求める: dp[n][p]
dp[i][v] = min(dp[i-1][v], dp[i-1][v-a[i-1]]+c[i-1])
<=> {
	chmin(&dp[i+1][v+a[i]], dp[i][v]+c[i]);
	chmin(&dp[i+1][v], dp[i][v]);
}
dp[0][0] = 0
dp[0][v] = inf (v != 0)
dp[i][v] = 0 (v = 0)
*/

ll dp[101][6][6][6][6][6];
ll inf = 1100100100100100100LL;

void chmin(ll &x, ll y) {
	if (x > y) x = y;
}

int main() {
	int n, k, p;
	cin >> n >> k >> p;
	vector<ll> c(n);
	vector<vector<int>> a(n, vector<int>(6, 0));
	rep(i, n) {
		cin >> c[i];
		rep(j, k) cin >> a[i][j];
	}

	// dpテーブル初期化
	rep(i, n + 1) {
		rep(v0, p + 1) rep(v1, p + 1) rep(v2, p + 1) rep(v3, p + 1) rep(v4, p + 1) {
			dp[i][v0][v1][v2][v3][v4] = inf;
		}
	}
	rep(i, n + 1) dp[i][0][0][0][0][0] = 0LL;

	rep(i, n) {
		rep(v0, p + 1) rep(v1, p + 1) rep(v2, p + 1) rep(v3, p + 1) rep(v4, p + 1) {
			chmin(
				dp[i+1][v0][v1][v2][v3][v4],
				dp[i][v0][v1][v2][v3][v4]
			);
			chmin(
				dp[i+1][min(v0+a[i][0], p)][min(v1+a[i][1], p)][min(v2+a[i][2], p)][min(v3+a[i][3], p)][min(v4+a[i][4], p)],
				dp[i][v0][v1][v2][v3][v4] + c[i]
			);
		}
	}

	vector<int> p_v(5, 0);
	rep(i, k) p_v[i] = p;

	ll ans = dp[n][p_v[0]][p_v[1]][p_v[2]][p_v[3]][p_v[4]];
	if (ans >= inf) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
}