#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	rep(i, n) cin >> s[i] >> t[i];
	rep(i, n) {
		bool fs = true, ft = true;
		rep(j, n) {
			if (i == j) continue;
			if (s[i] == s[j] || s[i] == t[j]) fs = false;
			if (t[i] == s[j] || t[i] == t[j]) ft = false;
		}
		if (fs == false && ft == false) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}