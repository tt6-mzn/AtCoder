#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	map<int, int> mp;
	rep(i, n) {
		int a;
		cin >> a;
		mp[a]++;
	}
	rep(i, m) {
		int b;
		cin >> b;
		if (mp[b] == 0) {
			cout << "No" << endl;
			return 0;
		}
		mp[b]--;
	}
	cout << "Yes" << endl;
	return 0;
}