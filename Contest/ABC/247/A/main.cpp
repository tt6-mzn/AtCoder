#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	string ans = "0000";
	rep(i, 3) ans[i + 1] = s[i];
	cout << ans << endl;
	return 0;
}