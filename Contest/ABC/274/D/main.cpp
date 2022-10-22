#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<int> xx, yy;
	rep(i, n) {
		if (i == 0) continue;
		if (i % 2 == 0) xx.push_back(a[i]);
		else yy.push_back(a[i]);
	}
	x = x - a[0];
	// xxの部分和でxをつくる
	map<int, bool> memo;
	memo[xx[0]] = true;
	memo[-xx[0]] = true;
	int mi = -xx[0];
	int ma = xx[0];
	for (int i = 1; i < xx.size(); i++) {
		map<int, bool> memo_new;
		for (int j = mi; j <= ma; j++) {
			if (memo[j]) {
				memo_new[j + xx[i]] = true;
				memo_new[j - xx[i]] = true;
				mi = min(mi, j - xx[i]);
				ma = max(ma, j + xx[i]);
			}
		}
		memo = memo_new;
	}
	if (memo[x] == false) {
		cout << "No" << endl;
		return 0;
	}
	// yyの部分和でyをつくる
	map<int, bool> memo_;
	memo_[yy[0]] = true;
	memo_[-yy[0]] = true;
	mi = -yy[0];
	ma = yy[0];
	for (int i = 1; i < yy.size(); i++) {
		map<int, bool> memo_new;
		for (int j = mi; j <= ma; j++) {
			if (memo_[j]) {
				memo_new[j + yy[i]] = true;
				memo_new[j - yy[i]] = true;
				mi = min(mi, j - yy[i]);
				ma = max(ma, j + yy[i]);
			}
		}
		memo_ = memo_new;
	}
	if (memo_[y] == false) {
		cout << "No" << endl;
		return 0;
	}
	cout << "Yes" << endl;
	return 0;
}