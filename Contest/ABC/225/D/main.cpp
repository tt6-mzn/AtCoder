#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, q;
	cin >> n >> q;
	vector<pair<int, int>> L(n);
	rep(i, n) L[i] = make_pair(-1, -1);
	rep(i, q) {
		int c, x, y;
		cin >> c;
		if (c == 1) {
			cin >> x >> y;
			x--; y--;
			L[x].second = y;
			L[y].first = x;
		}
		else if (c == 2) {
			cin >> x >> y;
			x--; y--;
			L[x].second = -1;
			L[y].first = -1;
		}
		else {
			/*
			rep(i, n) {
				cout << L[i].first + 1 << " " << L[i].second + 1 << endl;
			}
			*/
			vector<int> ans;
			cin >> x;
			x--;
			// cout << x << endl;
			// cout << L[x].first << " " << L[x].second << endl;
			while (L[x].first != -1) x = L[x].first;
			while (x != -1) {
				ans.push_back(x + 1);
				x = L[x].second;
			}
			cout << ans.size();
			rep(i, ans.size()) cout << " " << ans[i];
			cout << endl;
		}
	}
}