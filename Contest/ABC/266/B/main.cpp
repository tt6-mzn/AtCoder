#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

int main() {
	long long n; cin >> n;
	mint ans = n - 998244353LL;
	cout << ans.val() << endl;
	return 0;
}