#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int x;
	cin >> x;
	if (x == 0) {
		cout << "No" << endl;
		return 0;
	}
	if (x % 100 == 0) cout << "Yes" << endl;
	else cout << "No" << endl;
}