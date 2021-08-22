#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int q;
	cin >> q;

	bool rev = false;
	rep(i, q) {
		int t, a, b;
		cin >> t >> a >> b;
		a--; b--;
		if (t == 1) {
			if (rev == false) swap(s[a], s[b]);
			else {
				if (a < n) a = a + n;
				else a = a - n;
				if (b < n) b = b + n;
				else b = b - n;
				swap(s[a], s[b]);
			}
		}
		else {
			rev = !rev;
		}
	}
	if (rev == false) cout << s << endl;
	else cout << s.substr(n, n) + s.substr(0, n) << endl;
}