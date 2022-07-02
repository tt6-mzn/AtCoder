#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	int head = 0;
	rep(_, q) {
		int op, x;
		cin >> op >> x;
		if (op == 1) {
			head = (head - x + n) % n;
		}
		else {
			cout << s[(head + x - 1 + n) % n] << endl;
		}
	}
	return 0;
}