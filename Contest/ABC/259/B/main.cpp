#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	double a, b, d;
	cin >> a >> b >> d;
	double pi = 3.141592653589;
	printf("%.10lf ", a * cos(pi * d / 180.0) - b * sin(pi * d / 180.0));
	printf("%.10lf\n", a * sin(pi * d / 180.0) + b * cos(pi * d / 180.0));
	return 0;
