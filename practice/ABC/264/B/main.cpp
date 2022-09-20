#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int r, c; cin >> r >> c;
	if (max(abs(r - 8), abs(c - 8)) % 2 == 0) cout << "white" << endl;
	else cout << "black" << endl;
	return 0;
}