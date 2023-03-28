#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// BW->WB <=> Wをひとつ左にずらす操作
// WBWBWWW

int main() {
	string s;
	cin >> s;
	long long ans = 0;
	long long cnt_b = 0;
	rep(i, s.size()) {
		if (s[i] == 'W') ans += cnt_b;
		else cnt_b++;
	}
	cout << ans << endl;
	return 0;
}