#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int x, y, n;
	cin >> x >> y >> n;
	cout << min(x * n, y * (n / 3) + x * (n % 3)) << endl;
	return 0;
}