#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	set<int> st;
	rep(i, 5) {
		int t;
		cin >> t;
		st.insert(t);
	}
	cout << st.size() << endl;
	return 0;
}