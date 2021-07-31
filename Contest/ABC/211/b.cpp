#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<string> s(4);
	rep(i, 4) cin >> s[i];
	vector<bool> b(4, false);
	rep(i, 4) {
		if (s[i] == "H") b[0] = true;
		else if (s[i] == "2B") b[1] = true;
		else if (s[i] == "3B") b[2] = true;
		else b[3] = true;
	}
	bool flg = true;
	rep(i, 4) {
		if (b[i] == false) flg = false;
	}
	if (flg) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}