#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n, m;
vector<int> ans;

void dfs(int depth) {
	if (depth == n) {
		rep(_, ans.size()) { cout << ans[_] << " "; } cout << endl;
		return;
	}
	for (int i = ans[depth - 1] + 1; i <= m; i++) {
		ans[depth] = i;
		dfs(depth + 1);		
	}
}

int main() {
	cin >> n >> m;
	ans.assign(n, 1);
	for (int i = 1; i <= m; i++) {
		ans[0] = i;
		dfs(1);
	}
	return 0;
}