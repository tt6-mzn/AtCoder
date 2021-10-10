#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int l, q;
	cin >> l >> q;
	set<int> st;
	st.insert(0);
	st.insert(l);
	rep(i, q) {
		int c, x;
		cin >> c >> x;
		if (c == 1) {
			st.insert(x);
		}
		else {
			auto lower = st.lower_bound(x);
			auto t = lower;
			t--;
			cout << *lower - *t << endl;
		}
	}
}