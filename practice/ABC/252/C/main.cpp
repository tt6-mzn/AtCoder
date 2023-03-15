#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	int ans = 1100100100;
	rep(i, 10) {
		// iでそろえるには何秒かかるか求める
		int t = 0;
		map<int, int> mp;
		rep(j, n) {
			int pos = s[j].find(to_string(i));
			t = max(t, 10*mp[pos] + pos);
			mp[pos]++;
		}
		// 更新
		ans = min(ans, t);
	}
	cout << ans << endl;
	return 0;
}