#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s, t;
	cin >> s >> t;
	if (s == t) {
		cout << "Yes" << endl;
		return 0;
	}
	rep(i, s.size() - 1) {
		swap(s[i], s[i + 1]);
		if (s == t) {
			cout << "Yes" << endl;
			return 0;
		}
		swap(s[i], s[i + 1]);
	}
	cout << "No" << endl;
}