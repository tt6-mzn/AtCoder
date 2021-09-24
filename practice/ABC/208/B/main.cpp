#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int p;
	cin >> p;
	vector<int> fact(11, 1);
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= i; j++) {
			fact[i] *= j;
		}
	}
	int cnt = 0;
	for (int now = 10; now >= 1; now--) {
		if (p == 0) break;
		cnt += min(100, p / fact[now]);
		p -= min(100, p / fact[now]) * fact[now];
	}
	cout << cnt << endl;
}