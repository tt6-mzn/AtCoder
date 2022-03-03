#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int n;
vector<int> a, b;

void rot(int i) {
	int tmp = a[i + 2];
	a[i + 2] = a[i + 1];
	a[i + 1] = a[i];
	a[i] = tmp;
}

bool solve(int index) {
	if (index == n - 3) {
		rep(i, 3) {
			if (a[index] == b[index] && a[index + 1] == b[index + 1] && a[index + 2] == b[index + 2]) return true;
			rot(index);
		}
		return false;
	}
	int target = index;
	while (target < n && a[target] != b[index]) target++;
	if (target == n) return false;
	while (target > index) {
		if (target - 2 >= index) {
			rot(target - 2);
			target -= 2;
		}
		else {
			rot(target - 1);
			target++;
		}
	}
	return solve(index + 1);
}

int main() {
	cin >> n;
	a.resize(n); b.resize(n);
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];
	if (solve(0)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}