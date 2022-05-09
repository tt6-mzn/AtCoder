#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c, d, e, f, x;
	cin >> a >> b >> c >> d >> e >> f >> x;
	int taka = 0, aoki = 0;
	taka = (x / (a + c)) * a * b;
	taka += min(x % (a + c), a) * b;
	aoki = (x / (d + f)) * d * e;
	aoki += min((x % (d + f)), d) * e;
	if (taka == aoki) cout << "Draw" << endl;
	else if (taka > aoki) cout << "Takahashi" << endl;
	else cout << "Aoki" << endl;
	// cout << taka << " " << aoki << endl;
	return 0;
}