#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using ll = long long;

ll count(ll x) {
	ll ret = 0;
	rep(i, 63) {
		ret += x & 1;
		x >>= 1;
	}
	return ret;
}

int main() {
	int n;
	cin >> n;
	vector<ll> s(n), c(n);
	set<ll> t;
	rep(i, n) cin >> s[i] >> c[i];
	map<ll, ll> v;
	rep(i, n) {
		// s[i]のタイプと価値を求める
		while ((s[i] & 1) == 0) {
			s[i] >>= 1;
			c[i] <<= 1;
		}
		// 価値を加算
		v[s[i]] += c[i];
		t.insert(s[i]);
	}
	ll ans = 0;
	for (ll d : t) {
		ans += count(v[d]);
	}
	cout << ans << endl;
}