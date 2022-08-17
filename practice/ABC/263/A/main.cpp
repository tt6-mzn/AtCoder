#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<int> v(5);
	rep(i, 5) cin >> v[i];
	sort(v.begin(), v.end());
	if (v[0] == v[1] && v[2] == v[3] && v[3] == v[4]) {
		cout << "Yes" << endl;
		return 0;
	}
	else if (v[0] == v[1] && v[1] == v[2] && v[3] == v[4]) {
		cout << "Yes" << endl;
		return 0;
	}
	cout << "No" << endl;
	return 0;
}