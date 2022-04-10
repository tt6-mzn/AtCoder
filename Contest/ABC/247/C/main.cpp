#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string rec(int n) {
	if (n == 1) return "1";
	string tmp = rec(n - 1);
	return tmp + " " + to_string(n) + " " + tmp;
}

int main() {
	int n;
	cin >> n;
	cout << rec(n) << endl;
	return 0;
}