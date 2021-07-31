#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	vector<int> x(4);
	rep(i, 4) {
		x[i] = s[i] - '0';
	}
	bool flg = true;
	rep(i, 3) {
		if (x[i] != x[i + 1]) flg = false;
	}
	if (flg) {
		cout << "Weak" << endl;
		return 0;
	}
	flg = true;
	rep(i, 3) {
		if (x[i] == 9) {
			if (x[i + 1] != 0) flg = false;
		}
		else {
			if (x[i] + 1 != x[i + 1]) flg = false;
		}
	}
	if (flg) {
		cout << "Weak" << endl;
	}
	else {
		cout << "Strong" << endl;
	}
}