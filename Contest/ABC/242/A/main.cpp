#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	if (x <= a) {
		printf("%.12lf\n", 1.0);
		return 0;
	}
	if (a + 1 <= x && x <= b) {
		double ans;
		ans = (double)(c) / (double)(b - (a + 1) + 1);
		printf("%.12lf\n", ans);
		return 0;
	}
	printf("%.12lf\n", 0.0);
	return 0;
}