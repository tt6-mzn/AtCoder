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
	sort(a.begin(), a.end());
	rep(i, n) {
		if (a[i] != i + 1) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
}