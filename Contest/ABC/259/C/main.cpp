#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s, t;
	cin >> s >> t;
	if (s.size() > t.size()) {
		cout << "No" << endl;
		return 0;
	}
	int i = 0, j = 0;
	while (i < s.size() && j < t.size()) {
		if (s[i] != t[j]) {
			// cout << s[i] << " " << s[j] << endl;
			cout << "No" << endl;
			return 0;
		}
		
		int i_ = i, j_ = j;
		while (i_ < s.size() && s[i] == s[i_]) i_++;
		while (j_ < t.size() && t[j] == t[j_]) j_++;
		// cout << i_ - i << " " << j_ - j << endl;
		if (i_ - i == 1) {
			if (j_ - j != 1) {
				cout << "No" << endl;
				return 0;
			}
		}
		else {
			if (i_ - i > j_ - j) {
				cout << "No" << endl;
				return 0;
			}
		}
		i = i_;
		j = j_;
	}
	if (i == s.size() && j == t.size()) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}