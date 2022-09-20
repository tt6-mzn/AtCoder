#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s = "atcoder";
	int l, r; cin >> l >> r;
	l--; r--;
	for (int i = l; i <= r; i++) cout << s[i];
	cout << endl;
	return 0;
}