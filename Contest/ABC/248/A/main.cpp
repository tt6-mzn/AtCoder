#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	vector<bool> memo(10, false);
	for (char c : s) {
		memo[c - '0'] = true;
	}
	rep(i, 10) {
		if (!memo[i]) {
			cout << i << endl;
		}
	}
	return 0;
}