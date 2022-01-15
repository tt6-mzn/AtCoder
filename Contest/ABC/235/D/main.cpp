#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long a, n;
string str_n;
map<int, bool> mp;

bool rec(long long x, long long cnt) {
	// cout << x << " " << cnt << endl;
	if (mp[x]) return false;
	mp[x] = true;
	if (x == n) {
		cout << cnt << endl;
		return true;
	}
	stringstream ss; ss << x; string s = ss.str();
	if (s.size() > str_n.size()) return false;
	if (rec(a * x, cnt + 1)) return true;
	if (rec(stol(s[s.size() - 1] + s.substr(0, s.size() - 1)), cnt + 1)) return true;
	// cout << a * x << endl;
	return false;
}

int main() {
	cin >> a >> n;
	stringstream ss; ss << n; str_n = ss.str();
	if (!rec(1, 0)) cout << -1 << endl;
	return 0;
}