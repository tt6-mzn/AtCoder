#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	priority_queue<int> que;
	rep(i, k) que.push((-1) * p[i]);
	for (int i = k; i <= n; i++) {
		cout << (-1) * que.top() << endl;
		if (i == n) continue;
		que.push((-1) * p[i]);
		que.pop();
	}
	return 0;
}