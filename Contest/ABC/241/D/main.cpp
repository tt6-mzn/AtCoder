#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	multiset<long long> a;
	multiset<long long, greater<long long>> a_inv;
	long long q;
	cin >> q;
	rep(i, q) {
		long long op;
		cin >> op;
		if (op == 1) {
			long long x;
			cin >> x;
			a.insert(x);
			a_inv.insert(x);
		}
		else if (op == 2) {
			long long x, k;
			cin >> x >> k;
			auto it = a_inv.lower_bound(x);
			int j = 0;
			while (j < k - 1 && it != a_inv.end()) {
				it++;
				j++;
			}
			if (it != a_inv.end()) cout << *it << endl;
			else cout << -1 << endl;
		}
		else {
			long long x, k;
			cin >> x >> k;
			auto it = a.lower_bound(x);
			int j = 0;
			while (j < k - 1 && it != a.end()) {
				it++;
				j++;
			}
			if (it != a.end()) cout << *it << endl;
			else cout << -1 << endl;
		}
	}
	return 0;
}