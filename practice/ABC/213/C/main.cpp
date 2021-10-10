#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<int> a(n), b(n);
	set<int> a_, b_;
	map<int, int> ma, mb;
	rep(i, n) cin >> a[i] >> b[i];
	rep(i, n) {
		a_.insert(a[i]);
		b_.insert(b[i]);
	}
	int cnt = 1;
	for (int c : a_) {
		ma[c] = cnt;
		cnt++;
	}
	cnt = 1;
	for (int c : b_) {
		mb[c] = cnt;
		cnt++;
	}
	rep(i, n) {
		cout << ma[a[i]] << " " << mb[b[i]] << endl;
	}
}