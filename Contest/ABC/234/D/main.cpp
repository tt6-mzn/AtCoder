#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int op(int a, int b) {
	return a + b;
}

int e() {
	return 0;
}

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> p(n);
	rep(i, n) cin >> p[i];
	segtree<int, op, e> seg(n + 1);
	rep(i, k - 1) seg.set(p[i], 1); // 最初のk - 1個

	for (int i = k; i <= n; i++) {
		// p[0:i]のうちk番目に大きい(= i-k+1番目に小さい)値を出力

		// 値を追加
		seg.set(p[i - 1], 1);

		// seg.prod(0, l) = i-k+1となるlを見つける
		int l = 0, r = n + 1;
		while (r - l > 1) {
			int mid = (r + l) / 2;
			if (seg.prod(0, mid) <= i - k) l = mid;
			else r = mid;
		}
		cout << r - 0 << endl;
	}
	return 0;
}