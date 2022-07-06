#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long n;
vector<long long> x, y, p;
vector<bool> memo;

void dfs(int i, long long s) {
	// 頂点iに到達可能
	memo[i] = true;
	// 次のノード
	rep(j, n) {
		// 訪問済みなら無視
		if (memo[j]) continue;
		if (p[i] * s >= abs(x[i] - x[j]) + abs(y[i] - y[j])) {
			dfs(j, s);
		}
	}
}

bool can_reach(int v, long long s) {
	memo.assign(n, false);
	dfs(v, s);
	rep(i, n) if (!memo[i]) return false;
	return true;
}

bool is_ok(long long s) {
	rep(i, n) if (can_reach(i, s)) return true;
	return false;
}

int main() {
	cin >> n;
	rep(i, n) {
		long long s, t, u;
		cin >> s >> t >> u;
		x.push_back(s);
		y.push_back(t);
		p.push_back(u);
	}

	long long l = 0, r = 4000000100LL;
	while (r - l > 1) {
		long long mid = (l + r) / 2;
		if (!is_ok(mid)) l = mid;
		else r = mid;
	}
	cout << r << endl;
	return 0;
}