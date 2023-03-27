#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// a[i] <= upper
int upper = 200000;

int main() {
	int n;
	cin >> n;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];

	// cnt[x] := aにx以下の値がいくつあるか
	vector<long long> cnt(upper + 1, 0);

	// imos法でcntを求める
	for (auto ai : a) cnt[ai]++;
	rep(x, upper) cnt[x + 1] += cnt[x];

	long long ans = 0;
	rep(j, n) ans += cnt[a[j] - 1] * (n - cnt[a[j]]);
	cout << ans << endl;
	return 0;
}