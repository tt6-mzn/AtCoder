#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<pair<int, int>> a(n);
	rep(i, n) {
		int t;
		cin >> t;
		a[i] = {t, i};
	}
	sort(a.begin(), a.end());
	int s, t;
	tie(s, t) = a[a.size() - 2];
	cout << t + 1 << endl;
}