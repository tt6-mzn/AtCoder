#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

mint intpow(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        return intpow(a, b / 2) * intpow(a, b / 2);
    }
    else {
        return a * intpow(a, b / 2) * intpow(a, b / 2);
    }
}

int main() {
	int t;
	cin >> t;
	vector<mint> pow26(1000100, 1);
	for (int i = 1; i < 1000100; i++) pow26[i] = pow26[i - 1] * 26;
	
	rep(_, t) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		mint ans = 0;
		int m = (n + 1) / 2;
		rep(i, m) {
			mint tmp = s[i] - 'A';
			tmp *= pow26[m - i - 1];
			ans += tmp;
		}
		string tmp = s.substr(0, n / 2);
		reverse(tmp.begin(), tmp.end());
		string x = s.substr(0, m) + tmp;
		if (x <= s) ans++;
		cout << ans.val() << endl;
	}
	return 0;
}