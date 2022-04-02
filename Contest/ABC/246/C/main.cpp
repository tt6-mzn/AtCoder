#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, k, x;
	cin >> n >> k >> x;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	priority_queue<long long> que;
	rep(i, n) {
		long long t = min(k, a[i] / x); // t枚使える
		a[i] -= t * x;
		k -= t;
		que.push(a[i]); // 残りの値段をqueに
	}
	while (k > 0 && !que.empty()) { que.pop(); k--; }
	long long ans = 0;
	while (!que.empty()) { ans += que.top();  que.pop(); }
	cout << ans << endl;
	return 0;
}