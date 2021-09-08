#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<int> a(3);
	rep(i, 3) cin >> a[i];
	sort(a.begin(), a.end());
	cout << a[1] + a[2] << endl;
}