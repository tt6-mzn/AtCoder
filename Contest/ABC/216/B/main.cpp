#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> s(n), t(n);
	rep(i, n) {
		cin >> s[i];
		cin >> t[i];
	}
	rep(j, n) {
		rep(i, j) {
			if (s[i] == s[j] && t[i] == t[j]) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
}