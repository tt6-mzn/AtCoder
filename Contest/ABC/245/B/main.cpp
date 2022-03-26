#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	map<int, bool> mp;
	rep(i, n) {
		int a;
		cin >> a;
		mp[a] = true;
	}
	int ans = 0;
	while (mp[ans]) ans++;
	cout << ans << endl;
	return 0;
}