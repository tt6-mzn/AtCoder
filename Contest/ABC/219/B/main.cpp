#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	vector<string> s(3);
	rep(i, 3) cin >> s[i];
	string t;
	cin >> t;
	string ans;
	rep(i, t.size()) {
		ans += s[t[i] - '1'];
	}
	cout << ans << endl;
}