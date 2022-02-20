#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	a[0] = 1;
	rep(i, n) cin >> a[i + 1];
	vector<stack<int>> memo(200100);
	stack<int> st;
	int ans = 0;
	int now = 0;
	st.push(0);
	for (int i = 1; i <= n; i++) {
		ans++;
		if (a[i] == a[now]) {
			int t = memo[a[i]].top(); memo[a[i]].pop();
			memo[a[i]].push(t + 1);
			if (a[i] == memo[a[i]].top()) {
				memo[a[i]].pop();
				ans -= a[i];
				now = st.top(); st.pop();
			}
		}
		else {
			memo[a[i]].push(1);
			st.push(now);
			now = i;
		}
		cout << ans << endl;
	}
	return 0;
}