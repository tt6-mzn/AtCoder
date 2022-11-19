#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	rep(i, k) a.push_back(0);
	cout << a[k];
	for (int i = k + 1; i < a.size(); i++) cout << " " << a[i];
	cout << endl;
	return 0;
}