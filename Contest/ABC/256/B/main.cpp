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
	vector<int> base(4, 0);
	int p = 0;
	rep(i, n) {
		base[0] = 1;
		for (int j = 3; j >= 0; j--) {
			if (j + a[i] < 4) {
				base[j + a[i]] = base[j];
			}
			else p += base[j];
			base[j] = 0;
		}
	}
	cout << p << endl;
	return 0;
}