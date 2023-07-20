#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	set<string> tree;
	rep(_, n) {
		string s, s_rev;
		cin >> s;
		s_rev = s;
		reverse(s_rev.begin(), s_rev.end());
		tree.insert((s <= s_rev) ? s : s_rev);
	}
	cout << tree.size() << endl;
	return 0;
}