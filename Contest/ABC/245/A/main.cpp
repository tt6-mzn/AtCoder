#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	if (a != c) {
		if (a < c) cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
	}
	else if (b != d) {
		if (b < d) cout << "Takahashi" << endl;
		else cout << "Aoki" << endl;
	}
	else cout << "Takahashi" << endl;
	return 0;
}