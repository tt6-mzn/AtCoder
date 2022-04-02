#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	double a, b;
	cin >> a >> b;
	double r = sqrt(a * a + b * b);
	double x = a / r;
	double y = b / r;
	printf("%.10lf %.10lf\n", x, y);
	return 0;
}