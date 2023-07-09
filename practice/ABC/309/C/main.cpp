#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, k;
	cin >> n >> k;
	vector<pair<long long, long long>> ab(n);
	rep(i, n) cin >> ab[i].first >> ab[i].second;
	sort(ab.begin(), ab.end());
	long long s = 0;
	rep(i, n) s += ab[i].second;
	if (s <= k) {
		cout << 1 << endl;
		return 0;
	}
	rep(i, n) {
		s -= ab[i].second;
		if (s <= k) {
			cout << ab[i].first + 1 << endl;
			return 0;
		}
	}
	return 0;
}