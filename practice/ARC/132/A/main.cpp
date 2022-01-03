#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> r(n), c(n);
	rep(i, n) cin >> r[i];
	rep(i, n) cin >> c[i];
	int q;
	cin >> q;
	rep(i, q) {
		int x, y;
		cin >> x >> y;
		if (n - r[x - 1] >= c[y - 1]) cout << ".";
		else cout << "#";
	}
	cout << endl;
	return 0;
}