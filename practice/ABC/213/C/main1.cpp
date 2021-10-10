#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i] >> b[i];
	// aの座圧
	vector<int> a_ = a;
	sort(a_.begin(), a_.end());
	a_.erase(unique(a_.begin(), a_.end()), a_.end());
	// bの座圧
	vector<int> b_ = b;
	sort(b_.begin(), b_.end());
	b_.erase(unique(b_.begin(), b_.end()), b_.end());

	rep(i, n) {
		cout << lower_bound(a_.begin(), a_.end(), a[i]) - a_.begin() + 1 << " ";
		cout << lower_bound(b_.begin(), b_.end(), b[i]) - b_.begin() + 1 << endl;
	}
}