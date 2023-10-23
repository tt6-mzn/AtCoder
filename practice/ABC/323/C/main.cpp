#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	rep(i, m) cin >> a[i];
	vector<string> s(n);
	rep(i, n) cin >> s[i];

	int max_point = 0;
	rep(i, n) {
		int point = i;
		rep(j, m) if (s[i][j] == 'o') point += a[j];
		max_point = max(max_point, point);
	}

	rep(i, n) {
		// まだ解いていない問題のスコア
		vector<int> not_solve;
		rep(j, m) if (s[i][j] == 'x') not_solve.push_back(a[j]);
		sort(not_solve.begin(), not_solve.end(), greater<int>());
		// iの現在の持ち点
		int point = i;
		rep(j, m) if (s[i][j] == 'o') point += a[j];
		// 何問必要か
		int count = 0;
		while (point < max_point) {
			point += not_solve[count++];
		}
		cout << count << endl;
	}
	return 0;
}