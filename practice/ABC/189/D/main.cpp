#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	long long ans = 0;
	for (long long i = 0; i < 1LL << (n + 1); i++) {
		int x;
		if ((i >> 0) & 1) x = 1;
		else x = 0;
		for (int j = 1; j < n + 1; j++) {
			int y;
			if ((i >> j) & 1) y = 1;
			else y = 0;
			if (s[j - 1] == "AND") x &= y;
			else x |= y;
		}
		if (x == 1) ans++;
	}
	cout << ans << endl;
	return 0;
}