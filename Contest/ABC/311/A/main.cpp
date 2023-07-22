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
	vector<bool> ok(3, false);
	rep(i, n) {
		ok[s[i] - 'A'] = true;
		if (ok[0] && ok[1] && ok[2]) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}