#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, t, m;
bool hate[10][10];
int ans = 0;
vector<vector<int>> teams;

void dfs(int pos) {
	// 最終的にtチームできていればans++
	if (pos == n) {
		if (teams.size() == t) ans++;
		return;
	}
	// 既存のチームに人posを追加する
	rep(i, teams.size()) {
		// 追加するteamに仲の悪い人がいなければ
		if (all_of(
			teams[i].begin(),
			teams[i].end(),
			[&](int x){return !hate[x][pos];}
		)) {
			teams[i].push_back(pos);
			dfs(pos + 1);
			teams[i].pop_back();
		}
	}
	// pos単独teamを作る
	teams.push_back({pos});
	dfs(pos + 1);
	teams.pop_back();
}

int main() {
	cin >> n >> t >> m;
	rep(_, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		hate[a][b] = hate[b][a] = true;
	}
	dfs(0);
	cout << ans << endl;
	return 0;
}