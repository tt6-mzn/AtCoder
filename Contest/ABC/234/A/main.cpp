#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int f(int x) {
	return x * x + 2.0 * x + 3.0;
}

int main() {
	int t;
	cin >> t;
	cout << f(f(f(t) + t) + f(f(t))) << endl;
	return 0;
}