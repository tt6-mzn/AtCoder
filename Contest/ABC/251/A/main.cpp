#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	string ans = s + s + s + s + s + s;
	cout << ans.substr(0, 6) << endl;
	return 0;
}