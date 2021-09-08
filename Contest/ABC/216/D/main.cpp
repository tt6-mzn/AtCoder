#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<queue<int>> que_list(m);
	vector<queue<int>> memo(n);
	queue<int> L;
	rep(i, m) {
		int k;
		cin >> k;
		rep(j, k) {
			int a;
			cin >> a;
			a--;
			que_list[i].push(a);
			if (j == 0) {
				memo[a].push(i);
				if (memo[a].size() == 2) L.push(a);
			}
		}
	}
	int cnt = 0;
	while (!L.empty()) {
		int color = L.front(); L.pop();
		int index1 = memo[color].front(); memo[color].pop();
		int index2 = memo[color].front(); memo[color].pop();
		que_list[index1].pop();
		que_list[index2].pop();
		cnt += 2;
		if (!que_list[index1].empty()) {
			int new1 = que_list[index1].front();
			memo[new1].push(index1);
			if (memo[new1].size() == 2) L.push(new1);
		}
		if (!que_list[index2].empty()) {
			int new2 = que_list[index2].front();
			memo[new2].push(index2);
			if (memo[new2].size() == 2) L.push(new2);
		}
	}
	if (cnt == 2 * n) cout << "Yes" << endl;
	else cout << "No" << endl;
}