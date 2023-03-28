#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	if (s == "keyence") {
		cout << "YES" << endl;
		return 0;
	}
	rep(j, s.size()) rep(i, j) {
		string t = s.substr(0, i) + s.substr(j, s.size() - j);
		if (t == "keyence") {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	return 0;
}