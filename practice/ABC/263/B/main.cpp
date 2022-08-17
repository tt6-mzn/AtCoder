#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> p(n + 1);
	for (int i = 2; i <= n; i++) cin >> p[i];
	int now = n;
	int cnt = 0;
	while (now > 1) {
		now = p[now];
		cnt++;
	}
	cout << cnt << endl;
	return 0;
}