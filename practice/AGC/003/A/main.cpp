#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string str;
	cin >> str;
	int n = 0, w = 0, s = 0, e = 0;
	for (char c : str) {
		if (c == 'N') n++;
		if (c == 'W') w++;
		if (c == 'S') s++;
		if (c == 'E') e++;
	}
	if ((n > 0 && s == 0) || (s > 0 && n == 0)) {
		cout << "No" << endl;
		return 0;
	}
	// if (abs(n - s) & 1) {
	// 	cout << "No" << endl;
	// 	return 0;
	// }
	if ((w > 0 && e == 0) || (e > 0 && w == 0)) {
		cout << "No" << endl;
		return 0;
	}
	// if (abs(w - e) & 1) {
	// 	cout << "No" << endl;
	// 	return 0;
	// }
	cout << "Yes" << endl;
	return 0;
}