#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, x;
	cin >> n >> x;
	int s = 0;
	rep(i, n) {
		int a;
		cin >> a;
		if (i % 2 == 1) a--;
		s += a;
	}
	if (s <= x) {
		cout << "Yes" << endl;
	}
	else {
		cout << "No" << endl;
	}
}