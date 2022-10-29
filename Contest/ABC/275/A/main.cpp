#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int ans = 0, index;
	rep(i, n) {
		if (ans < a[i]) {
			ans = a[i];
			index = i;
		}
	}
	cout << index + 1 << endl;
	return 0;
}