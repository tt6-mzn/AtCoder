#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	int a, b, c;
	a = s[0] - '0';
	b = s[1] - '0';
	c = s[2] - '0';
	cout << 100 * a + 10 * b + c + 100 * b + 10 * c + a + 100 * c + 10 * a + b << endl;
	return 0;
}