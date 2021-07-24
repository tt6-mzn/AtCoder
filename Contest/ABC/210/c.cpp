#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, k;
	cin >> n >> k;
	vector<long long> c(n);
	rep(i, n) cin >> c[i];
	map<long long, long long> mp;
	long long ans = 0, t_ans = 0;
	rep(i, n - k + 1) {
		if (i == 0) {
			rep(j, k) {
				mp[c[j]]++;
				if (mp[c[j]] == 1) ans++;
			}
			t_ans = ans;
		}
		else {
			mp[c[i - 1]]--;
			if (mp[c[i - 1]] == 0) t_ans--;
			mp[c[i + k - 1]]++;
			if (mp[c[i + k - 1]] == 1) t_ans++;
			ans = max(ans, t_ans);
		}
	}
	cout << ans << endl;
}