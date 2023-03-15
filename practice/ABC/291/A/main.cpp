#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	int ans = 0;
	while ('a' <= s[ans] && s[ans] <= 'z') ans++;
	cout << ans + 1 << endl;
	return 0;
}