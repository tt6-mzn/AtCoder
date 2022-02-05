#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int t;
	cin >> t;
	rep(_, t) {
		long long at, st;
		cin >> at >> st;
		bitset<64> ab(at), sb(st); 
		string a = ab.to_string(), s = sb.to_string();
		reverse(a.begin(), a.end());
		reverse(s.begin(), s.end());
		int n = a.size() - 1;
		while (a[n] == '0' && s[n] == '0') n--;
		// cout << a << endl;
		// cout << s << endl;
		int c = 0;
		bool flg = true;
		// cout << n << endl;
		rep(i, n + 1) {
			if (a[i] == '0' && s[i] == '0') {
				if (c > 0) c--;
			}
			if (a[i] == '0' && s[i] == '1') {
				if (c > 0) c--;
			}
			if (a[i] == '1' && s[i] == '0') {
				if (c == 0) c++;
				else flg = false;
			}
			if (a[i] == '1' && s[i] == '1') {
				if (c == 0) flg = false;
				else c++;
			}
			if (c < 0) flg = false;
		}
		if (flg && c == 0) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}