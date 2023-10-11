#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	auto index = s.find("ABC");
	if (index != string::npos) {
		cout << index + 1 << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}