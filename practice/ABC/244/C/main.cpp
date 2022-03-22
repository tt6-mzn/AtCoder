#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	queue<int> que;
	map<int, bool> mp;
	for (int i = 1; i <= 2 * n + 1; i++) que.push(i);
	rep(_, 2 * n) {
		while (mp[que.front()]) que.pop();
		int ans = que.front(); que.pop();
		mp[ans] = true;
		cout << ans << endl; cout << flush;
		int opp;
		cin >> opp;
		mp[opp] = true;
	}
	return 0;
}