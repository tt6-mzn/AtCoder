#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int l, q;
	cin >> l >> q;
	set<int> tree;
	rep(i, q) {
		int c, x;
		cin >> c >> x;
		if (c == 1) {
			tree.insert(x);
		}
		else {
			if (tree.empty()) {
				cout << l << endl;
				continue;
			}
			auto lower = tree.lower_bound(x);
			if (lower == tree.end()) {
				auto t = lower;
				t--;
				cout << l - *t << endl;
				continue;
			}
			if (lower == tree.begin()) {
				cout << *lower << endl;
				continue;
			}
			auto t = lower;
			t--;
			cout << *lower - *t << endl;
		}
	}
}