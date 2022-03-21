#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint;

int main() {
	mint::set_mod(4);
	int n;
	cin >> n;
	string t;
	cin >> t;
	int x = 0, y = 0;
	mint d = 1;
	for (char c : t) {
		if (c == 'R') { d++; continue; }
		if (d.val() == 0) y++;
		if (d.val() == 1) x++;
		if (d.val() == 2) y--;
		if (d.val() == 3) x--;
	}
	cout << x << " " << y << endl;
	return 0;
}