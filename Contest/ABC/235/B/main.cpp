#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> h(n);
	rep(i, n) cin >> h[i];
	int i = 0;
	while (i < n - 1 && h[i] < h[i + 1]) i++;
	cout << h[i] << endl;
	return 0;
}