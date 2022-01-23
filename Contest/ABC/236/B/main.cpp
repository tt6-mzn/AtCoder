#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(4 * n - 1);
	rep(i, 4 * n - 1) cin >> a[i];
	vector<int> memo(n + 1, 0);
	for (int t : a) memo[t]++;
	for (int i = 1; i < n + 1; i++) {
		if (memo[i] == 3) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}