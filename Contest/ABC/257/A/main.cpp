#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, x;
	cin >> n >> x;
	string s = "";
	string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (char c : alp) {
		rep(i, n) s += c;
	}
	cout << s[x - 1] << endl;
	return 0;
}