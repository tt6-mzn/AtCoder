#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	vector<int> q(n);
	rep(i, n) {
		q[p[i] - 1] = i + 1;
	}
	cout << q[0];
	for (int i = 1; i < n; i++) cout << " " << q[i];
	cout << endl;
}