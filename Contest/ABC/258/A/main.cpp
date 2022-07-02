#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int k;
	cin >> k;
	cout << 21 + k / 60 << ":";
	if (to_string(k % 60).size() == 1) {
		cout << 0 << k % 60 << endl;
	}
	else {
		cout << k % 60 << endl;
	}
	return 0;
}