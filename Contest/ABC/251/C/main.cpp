#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	vector<string> s(n);
	vector<long long> t(n);
	rep(i, n) cin >> s[i] >> t[i];
	long long ans_ind = -1, ans_score = -1;
	map<string, bool> mp;
	rep(i, n) {
		if (mp[s[i]] == false) {
			if (ans_score < t[i]) {
				ans_score = t[i];
				ans_ind = i;
			}
			mp[s[i]] = true;
		}
	}
	cout << ans_ind + 1 << endl;
	return 0;
}