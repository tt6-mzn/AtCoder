#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, q;
	cin >> n >> q;
	map<pair<long long, long long>, bool> mp;
	rep(_, q) {
		long long t, a, b;
		cin >> t >> a >> b;
		if (t == 1) mp[{a, b}] = true;
		if (t == 2) mp[{a, b}] = false;
		if (t == 3) {
			if (mp[{a, b}] && mp[{b, a}]) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}