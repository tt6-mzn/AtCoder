#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s; cin >> s;
	if (s[0] == 'M') cout << 5 << endl;
	else if (s[0] == 'T') {
		if (s[1] == 'u') cout << 4 << endl;
		else cout << 2 << endl;
	}
	else if (s[0] == 'W') cout << 3 << endl;
	else if (s[0] == 'F') cout << 1 << endl;
	return 0;
}