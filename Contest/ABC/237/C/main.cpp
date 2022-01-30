#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	int i = 0, j = s.size() - 1;
	int left = 0, right = 0;
	while (i < s.size() && s[i] == 'a') {
		left++;
		i++;
	}
	while (j >= 0 && s[j] == 'a') {
		right++;
		j--;
	}
	if (j == 0) {
		cout << "Yes" << endl;
		return 0;
	}
	if (left > right) {
		cout << "No" << endl;
		return 0;
	}
	string subs = s.substr(i, j - i + 1);
	string subs_ = subs;
	reverse(subs_.begin(), subs_.end());
	if (subs == subs_) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
	return 0;
}