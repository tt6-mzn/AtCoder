#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	if (s[s.size() - 1] == 'r') {
		cout << "er" << endl;
	}
	else {
		cout << "ist" << endl;
	}
}