#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<int> a(10);
	rep(i, 10) cin >> a[i];
	cout << a[a[a[0]]] << endl;
	return 0;
}