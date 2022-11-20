#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, x;
	cin >> n >> x;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	rep(i, n) {
		if (p[i] == x) {
			cout << i + 1 << endl;
			return 0;
		}
	}
	return 0;
}