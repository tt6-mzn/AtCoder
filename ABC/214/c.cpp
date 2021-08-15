#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	vector<long long> s(n), t(n);
	rep(i, n) cin >> s[i];
	rep(i, n) cin >> t[i];
	priority_queue<pair<long long, long long>> que;
	rep(i, n) que.push({(-1) * t[i], i});
	long long cnt = 0;
	vector<long long> ans(n, -1);
	while (cnt < n) {
		int ti, i;
		tie(ti, i) = que.top(); que.pop();
		ti *= -1;
		if (ans[i] == -1) {
			ans[i] = ti;
			cnt++;
		}
		que.push({(-1) * (ti + s[i]), (i + 1) % n});
	}
	rep(i, n) {
		cout << ans[i] << endl;
	}
}