#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string e() {
	return "z";
}

string op(string a, string b) {
	return min(a, b);
}

int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	segtree<string, op, e> seg(n);
	rep(i, n) seg.set(i, s.substr(i, 1));
	int now = 0;
	string ans = "";
	rep(i, k) {
		// cout << now << " " << n - k + 1 + i << endl;
		string tmp = seg.prod(now, n - k + 1 + i);
		ans += tmp;
		while (s.substr(now, 1) != tmp) now++;
		now++;
	}
	cout << ans << endl;
	return 0;
}