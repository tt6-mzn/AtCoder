#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int q;
	cin >> q;
	queue<int> que;
	priority_queue<int> pq;
	rep(i, q) {
		int c, x;
		cin >> c;
		if (c == 1) {
			cin >> x;
			que.push(x);
		}
		else if (c == 2) {
			if (!pq.empty()) {
				int ans = pq.top(); pq.pop();
				cout << (-1) * ans << endl;
			}
			else {
				int ans = que.front(); que.pop();
				cout << ans << endl;
			}
		}
		else {
			while (!que.empty()) {
				pq.push((-1) * que.front()); que.pop();
			}
		}
	}
}