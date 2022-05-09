#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	bool low = false, upp = false;
	for (char c : s) {
		if (islower(c)) low = true;
		if (isupper(c)) upp = true;
	}
	if (!(low && upp)) {
		cout << "No" << endl;
		return 0;
	}
	sort(s.begin(), s.end());
	rep(i, s.size() - 1) {
		if (s[i] == s[i + 1]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}