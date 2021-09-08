#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	if (s.size() == 4) cout << s[0] << s[1];
	else cout << s[0];
	if (s[s.size() - 1] - '0' <= 2) cout <<  "-" << endl;
	else if (s[s.size() - 1] - '0' <= 6) cout << endl;
	else cout << "+" << endl;
}