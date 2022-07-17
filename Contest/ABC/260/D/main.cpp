#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)



int main() {
	long long n, k;
	cin >> n >> k;
	vector<long long> p(n);
	rep(i, n) cin >> p[i];
	rep(i, n) p[i]--;
	set<pair<long long, long long>> st;
	vector<long long> arrow(n, -1);
	map<int, int> ans;
	rep(i, n) {
		auto elem = make_pair(p[i], 1);
		auto it = st.lower_bound(elem);
		if (it == st.end()) {
			if (k == 1) {
				ans[elem.first] = i + 1;
				continue;
			}
			st.insert(elem);
			continue;
		}
		auto elem_ = *it; st.erase(it);
		if (elem_.second + 1 == k) {
			ans[elem.first] = i + 1;
			arrow[elem_.first] = elem.first;
			// ans[elem_.first] = i;
			continue;
		}
		arrow[elem_.first] = elem.first;
		st.insert(make_pair(elem.first, elem_.second + 1));
	}

	// rep(_, arrow.size()) { cout << arrow[_] << " "; } cout << endl;
	
	rep(i, n) {
		int i_ = i;
		while (arrow[i_] != -1) i_ = arrow[i_];
		if (i != i_) arrow[i] = i_;
		// cout << "hello" << endl;
		if (ans[i_] == 0) {
			cout << -1 << endl;
		}
		else {
			cout << ans[i_] << endl;
		}
		// cout << ans[uf.leader(p[i])] << endl;
	}
	return 0;
}