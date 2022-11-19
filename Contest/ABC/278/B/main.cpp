#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int h, m;
	cin >> h >> m;
	while (1) {
		int a, b, c, d;
		a = h / 10;
		b = h % 10;
		c = m / 10;
		d = m % 10;
		swap(b, c);
		int h_, m_;
		h_ = 10 * a + b;
		m_ = 10 * c + d;
		if (0 <= h_ && h_ < 24 && 0 <= m_ && m_ < 60) {
			cout << h << " " << m << endl;
			return 0;
		}
		if (m == 59) {
			m = 0;
			h = (h + 1) % 24;
		}
		else {
			m++;
		}
	}
	return 0;
}