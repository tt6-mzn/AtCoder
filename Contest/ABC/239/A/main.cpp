#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	double h;
	cin >> h;
	printf("%.9lf\n", sqrt(h * (12800000.0 + h)));
	return 0;
}