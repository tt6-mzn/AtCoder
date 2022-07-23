#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	map<string, int> mp;
	rep(i, n) {
		if (mp[s[i]] == 0) {
			cout << s[i] << endl;
		}
		else {
			cout << s[i] << "(" << mp[s[i]] << ")" << endl;
		}
		mp[s[i]]++;
	}
	return 0;
}