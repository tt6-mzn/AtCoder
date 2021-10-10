#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	rep(i, 26) {
		int p;
		cin >> p;
		cout << (char)('a' + (p - 1));
	}
	cout << endl;
}