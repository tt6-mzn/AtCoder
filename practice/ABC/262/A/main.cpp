#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int y;
	cin >> y;
	while (y % 4 != 2) y++;
	cout << y << endl;
	return 0;
}