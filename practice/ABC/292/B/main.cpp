#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> cnt(n + 1, 0);
	rep(_, q) {
		int op, x;
		cin >> op >> x;
		if (op == 1) cnt[x]++;
		if (op == 2) cnt[x] = 2;
		if (op == 3) {
			if (cnt[x] == 2) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}