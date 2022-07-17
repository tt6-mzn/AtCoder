#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	sort(s.begin(), s.end());
	if (s[0] == s[1] && s[1] == s[2]) {
		cout << -1 << endl;
	}
	else if (s[0] == s[1]) {
		cout << s[2] << endl;
	}
	else if (s[1] == s[2]) {
		cout << s[0] << endl;
	}
	else {
		cout << s[0] << endl;
	}
	return 0;
}