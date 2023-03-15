#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	map<tuple<int, int>, bool> mp;
	int x = 0, y = 0;
	mp[{x, y}] = true;
	for (char c : s) {
		if (c == 'R') x++;
		if (c == 'L') x--;
		if (c == 'U') y++;
		if (c == 'D') y--;
		if (mp[{x, y}]) {
			cout << "Yes" << endl;
			return 0;
		}
		mp[{x, y}] = true;
	}
	cout << "No" << endl;
	return 0;
}