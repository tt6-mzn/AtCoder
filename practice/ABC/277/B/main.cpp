#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	string s1 = "HDCS";
	string s2 = "A23456789TJQK";
	for (auto si : s) {
		if (s1.find(si[0], 0) == string::npos || s2.find(si[1], 0) == string::npos) {
			cout << "No" << endl;
			return 0;
		}
	}
	rep(i, n) rep(j, n) {
		if (i == j) continue;
		if (s[i] == s[j]) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}