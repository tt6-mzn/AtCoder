#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, p;
	cin >> n >> p;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	int cnt = 0;
	rep(i, n) {
		if (a[i] < p) cnt++;
	}
	cout << cnt << endl;
}