#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	string s, t;
	cin >> s >> t;
	bool prefix = false, suffix = false;
	if (t.substr(0, s.size()) == s) prefix = true;
	if (t.substr(t.size() - s.size(), s.size()) == s) suffix = true;
	if (prefix && suffix) cout << 0 << endl;
	else if (prefix && !suffix) cout << 1 << endl;
	else if (!prefix && suffix) cout << 2 << endl;
	else cout << 3 << endl;
	return 0;
}