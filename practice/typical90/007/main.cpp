#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	set<long long> a;
	long long inf = 1100100100100100100LL;
	a.insert(inf); a.insert(-inf);
	rep(i, n) {
		long long t;
		cin >> t;
		a.insert(t);
	}
	int q;
	cin >> q;
	rep(_, q) {
		long long b;
		cin >> b;
		auto it = a.lower_bound(b);
		long long left, right;
		right = *it;
		it--;
		left = *it;
		cout << min(abs(left - b), abs(right - b)) << endl;
	}
	return 0;
}