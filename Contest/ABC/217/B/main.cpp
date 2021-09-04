#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<string> s(3);
	rep(i, 3) cin >> s[i];
	vector<bool> memo(4, false);
	rep(i, 3) {
		if (s[i] == "ABC") memo[0] = true;
		else if (s[i] == "AGC") memo[1] = true;
		else if (s[i] == "AHC") memo[2] = true;
		else memo[3] = true;
	}
	if (memo[0] == false) cout << "ABC" << endl;
	else if (memo[1] == false) cout << "AGC" << endl;
	else if (memo[2] == false) cout << "AHC" << endl;
	else cout << "ARC" << endl;
}