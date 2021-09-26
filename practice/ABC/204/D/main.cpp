#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> t(n);
	rep(i, n) cin >> t[i];
	sort(t.begin(), t.end(), greater<int>());
	int x = 0, y = 0;
	for (int a : t) {
		if (x <= y) x += a;
		else y += a;
	}
	cout << max(x, y) << endl;
}