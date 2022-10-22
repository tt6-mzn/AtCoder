#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s; cin >> s;
	vector<int> v(7, 0);
	if (s[0] == '1') {
		cout << "No" << endl;
		return 0;
	}
	if (s[1] == '1') v[2]++;
	if (s[2] == '1') v[4]++;
	if (s[3] == '1') v[1]++;
	if (s[4] == '1') v[3]++;
	if (s[5] == '1') v[5]++;
	if (s[6] == '1') v[0]++;
	if (s[7] == '1') v[2]++;
	if (s[8] == '1') v[4]++;
	if (s[9] == '1') v[6]++;
	rep(j, 7) rep(i, j) {
		if (v[i] > 0 && v[j] > 0) {
			for (int k = i + 1; k < j; k++) {
				if (v[k] == 0) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	return 0;
}