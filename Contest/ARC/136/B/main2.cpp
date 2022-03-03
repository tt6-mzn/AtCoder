#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;

void rot(int i, vector<int>& a) {
	int tmp = a[i + 2];
	a[i + 2] = a[i + 1];
	a[i + 1] = a[i];
	a[i] = tmp;
}

bool solve(int index, vector<int> a, vector<int>& b) {
	if (index == n - 3) {
		rep(i, 3) {
			if (a[index] == b[index] && a[index + 1] == b[index + 1] && a[index + 2] == b[index + 2]) return true;
			rot(index, a);
		}
		return false;
	}
	for (int target = index; target < n; target++) {
		if (a[target] == b[index]) {
			int target_ = target;
			vector<int> a_(n);
			rep(i, n) a_[i] = a[i];
			while (target_ > index) {
				if (target_ - 2 >= index) {
					rot(target_ - 2, a_);
					target_ -= 2;
				}
				else {
					rot(target_ - 1, a_);
					target_++;
				}
			}
			if (solve(index + 1, a_, b)) return true;
			rep(i, n) a_[i] = a[i];
			if (0 <= target_ - 1 && target_ + 1 < n) {
				rot(target_ - 1, a_);
				target_++;
			}
			while (target_ > index) {
				if (target_ - 2 >= index) {
					rot(target_ - 2, a_);
					target_ -= 2;
				}
				else {
					rot(target_ - 1, a_);
					target_++;
				}
			}
			if (solve(index + 1, a_, b)) return true;
		}
	}
	return false;
}

int main() {
	cin >> n;
	vector<int> a(n), b(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	if (solve(0, a, b)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
