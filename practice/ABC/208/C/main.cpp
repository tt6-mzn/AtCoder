#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, k;
	cin >> n >> k;
	vector<long long> a(n), a_(n);
	rep(i, n) {
		cin >> a[i];
		a_[i] = a[i];
	}
	if (k % n == 0) {
		rep(i, n) {
			cout << k / n << endl;
		}
		return 0;
	}
	sort(a_.begin(), a_.end());
	long long ak = a_[k % n];
	rep(i, n) {
		if (a[i] < ak) {
			cout << k / n + 1 << endl;
		}
		else {
			cout << k / n << endl;
		}
	}
}