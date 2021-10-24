#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int dfs(
	int v,
	vector<int>& ans,
	vector<vector<pair<int, int>>>& rp,
	vector<vector<pair<int, int>>>& cp,
	vector<int>& a,
	vector<pair<int, int>>& itorc
) {
	if (ans[v] != -1) return ans[v];
	int vr, vc;
	tie(vr, vc) = itorc[v];
	auto it = lower_bound(rp[vr].begin(), rp[vr].end(), make_pair(a[v], v));
	bool flg = true;
	while (it != rp[vr].end()) {
		flg = false;
		int ai, next;
		tie(ai, next) = *it;
		ans[v] = max(dfs(v, ans, rp, cp, a, itorc) + 1, ans[v]);
		it++;
	}
	it = lower_bound(cp[vc].begin(), cp[vc].end(), make_pair(a[v], v));
	while (it != cp[vc].end()) {
		flg = false;
		int ai, next;
		tie(ai, next) = *it;
		ans[v] = max(dfs(v, ans, rp, cp, a, itorc) + 1, ans[v]);
		it++;
	}
	if (flg) {
		ans[v] = 0;
		return 0;
	}
	return ans[v];
}

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n);
	vector<vector<pair<int, int>>> rp(h), cp(w);
	vector<pair<int, int>> itorc;
	rep(i, n) {
		int r, c, ai;
		cin >> r >> c >> ai;
		a[i] = ai;
		rp[r - 1].push_back({ai, i});
		cp[c - 1].push_back({ai, i});
		itorc.push_back({r - 1, c - 1});
	}
	rep(i, h) sort(rp[i].begin(), rp[i].end());
	rep(i, w) sort(cp[i].begin(), cp[i].end());
	vector<int> ans(n, -1);
	cout << dfs(1, ans, rp, cp, a, itorc) << endl;
	/*
	rep(i, n) {
		if (ans[i] == -1) dfs(i, ans, rp, cp, a, itorc);
	}
	*/
	cout << ans[0];
	for (int i = 1; i < n; i++) cout << " " << ans[i];
	cout << endl;
}