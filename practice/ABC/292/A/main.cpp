#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	// string s;
	// cin >> s;
	// rep(i, s.size()) s[i] = toupper(s[i]);
	// cout << s << endl;

	// string s;
	// cin >> s;
	// rep(i, s.size()) cout << (char)('A' + (s[i] - 'a'));
	// cout << endl;

	string s;
	cin >> s;
	transform(s.begin(), s.end(), s.begin(), ::toupper);
	cout << s << endl;
	
	return 0;
}