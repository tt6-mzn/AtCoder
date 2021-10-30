#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<vector<int>> G(n);
	rep(i, n - 1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	rep(i, n) {
		if (G[i].size() == n - 1) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
}