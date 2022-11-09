#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<string> s(10);
	rep(i, 10) cin >> s[i];
	int a = 0, b = 9;
	while (s[a] == "..........") a++;
	while (s[b] == "..........") b--;
	int c = 0, d = 9;
	while (s[a][c] == '.') c++;
	while (s[a][d] == '.') d--;
	cout << a + 1 << " " << b + 1 << endl;
	cout << c + 1 << " " << d + 1 << endl;
	return 0;
}