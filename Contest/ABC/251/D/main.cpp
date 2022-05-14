#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long w;
	cin >> w;
	long long now = 3, m = 3 * now - 3;
	for (int i = 1; i <= w; i++) {
		if (w > m) {
			now++;
			m = 3 * now - 3;
		}
	}
	cout << now << endl;
	cout << 1;
	for (int i = 2; i <= now; i++) cout << " " << i;
	cout << endl;
	return 0;
}