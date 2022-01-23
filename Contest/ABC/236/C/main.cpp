#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> s(n), t(m);
	rep(i, n) cin >> s[i];
	rep(i, m) cin >> t[i];
	map<string, bool> memo;
	for (string name : t) memo[name] = true;
	for (string name : s) {
		if (memo[name]) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}