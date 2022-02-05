#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, l;
	cin >> n >> l;
	long long k;
	cin >> k;
	vector<long long> a(n), b(n + 1);
	rep(i, n) cin >> a[i];
	a.push_back(l);
	b[0] = a[0];
	for (int i = 1; i < n + 1; i++) b[i] = a[i] - a[i - 1];
	// スコア>=1 -> 可能, スコア>=l+1 -> 不可能
	long long left = 1, right = l + 1;
	while (right - left > 1) {
		long long mid = left + (right - left) / 2;
		// スコアがmid以上となるようにk + 1個に分割できるか?
		long long cnt = 0, now = 0;
		while (now < n + 1) {
			long long sum = 0;
			while (now < n + 1 && sum < mid) sum += b[now++];
			cnt++;
		}
		if (cnt >= k + 1) left = mid;
		else right = mid;
	}
	cout << left << endl;
	return 0;
}