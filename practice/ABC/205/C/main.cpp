#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a >= 0 && b >= 0) {
		if (a == b) cout << "=" << endl;
		else if (a > b) cout << ">" << endl;
		else cout << "<" << endl;
	}
	else if (a >= 0) {
		if (c % 2 == 0) {
			if (a == abs(b)) cout << "=" << endl;
			else if (a > abs(b)) cout << ">" << endl;
			else cout << "<" << endl;
		}
		else {
			cout << ">" << endl;
		}
	}
	else if (b >= 0) {
		if (c % 2 == 0) {
			if (abs(a) == b) cout << "=" << endl;
			else if (abs(a) > b) cout << ">" << endl;
			else cout << "<" << endl;
		}
		else {
			cout << "<" << endl;
		}
	}
	else {
		if (c % 2 == 0) {
			if (abs(a) == abs(b)) cout << "=" << endl;
			else if (abs(a) > abs(b)) cout << ">" << endl;
			else cout << "<" << endl;
		}
		else {
			if (abs(a) == abs(b)) cout << "=" << endl;
			else if (abs(a) > abs(b)) cout << "<" << endl;
			else cout << ">" << endl;
		}
	}
}