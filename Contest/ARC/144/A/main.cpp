#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	long long m = 2 * n;
	long long m_ = m;
	string ans;
	while (m_ > 0) {
		if (m_ >= 8) {
			ans += "8";
			m_ -= 8;
		}
		else {
			ans += to_string(m_);
			m_ -= m_;
		}
	}
	reverse(ans.begin(), ans.end());
	cout << m << endl;
	rep(i, ans.size()) cout << (ans[i] - '0') / 2;
	cout << endl;
	return 0;
}