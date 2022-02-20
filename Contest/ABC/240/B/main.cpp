#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	set<int> a;
	rep(i, n) {
		int t;
		cin >> t;
		a.insert(t);
	}
	cout << a.size() << endl;
	return 0;
}