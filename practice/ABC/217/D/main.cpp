#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int l, q;
	cin >> l >> q;
	set<int> st = {0, l};
	rep(i, q) {
		int c, x;
		cin >> c >> x;
		if (c == 1) st.insert(x);
		else {
			auto lower = st.lower_bound(x);
			int a = *lower;
			lower--;
			int b = *lower;
			cout << a - b << endl;
		}
	}
}