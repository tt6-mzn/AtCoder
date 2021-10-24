#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;
	vector<string> ss;
	rep(i, s.size()) {
		ss.push_back(s);
		s = s.substr(s.size() - 1, 1) + s.substr(0, s.size() - 1);
	}
	sort(ss.begin(), ss.end());
	cout << ss[0] << endl << ss[ss.size() - 1] << endl;
}