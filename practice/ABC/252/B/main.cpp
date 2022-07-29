#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	int max_a = -1;
	rep(i, n) {
		cin >> a[i];
		max_a = max(max_a, a[i]);
	}

	map<int, bool> mp;
	rep(i, k) {
		int b;
		cin >> b;
		mp[b - 1] = true;
	}

	rep(i, n) {
		if (a[i] == max_a) {
			if (mp[i]) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}