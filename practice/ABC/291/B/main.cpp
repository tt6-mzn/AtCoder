#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> x(5 * n);
	rep(i, 5 * n) cin >> x[i];
	sort(x.begin(), x.end());
	auto s = accumulate(x.begin() + n, x.end() - n, 0);
	printf("%.15lf\n", (double)s / (double)(3 * n));
	return 0;
}