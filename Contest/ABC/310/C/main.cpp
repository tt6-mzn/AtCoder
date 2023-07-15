#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	set<string> s, s_;
	rep(i, n) {
		string si;
		cin >> si;
		string si_rev = si;
		s.insert(si);
		reverse(si_rev.begin(), si_rev.end());
		s.insert(si_rev);
		if (si == si_rev) s_.insert(si);
	}
	cout << (s.size() + s_.size()) / 2 << endl;
	return 0;
}