#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (a <= b && b <= c) cout << "Yes" << endl;
	else if (c <= b && b <= a) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}