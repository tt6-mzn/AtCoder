#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string n;
	cin >> n;
	sort(n.begin(), n.end(), greater<char>());
	int m = 1;
	rep(i, n.size()) m *= 2;
	long long ans = -1;
	rep(i, m) {
		string a = "", b = "";
		rep(j, n.size()) {
			if ((i >> j) & 1) a.push_back(n[j]);
			else b.push_back(n[j]);
			if (a.size() == 0 || b.size() == 0) continue;
			if (a[0] == '0' || b[0] == '0') continue;
			ans = max(ans, (long long)stol(a) * (long long)stol(b));
		}
	}
	cout << ans << endl;
}