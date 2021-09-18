#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int x;
	cin >> x;
	if (x < 40) cout << 40 - x << endl;
	else if (x < 70) cout << 70 - x << endl;
	else if (x < 90) cout << 90 - x << endl;
	else cout << "expert" << endl;
}