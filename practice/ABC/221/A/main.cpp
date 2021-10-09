#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b;
	cin >> a >> b;
	long long ans = 1;
	rep(i, a - b) ans *= 32;
	cout << ans << endl;
}