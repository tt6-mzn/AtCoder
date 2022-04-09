#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool isOK(long long m, vector<long long> &a, long long k) {
	long long index = 0;
	long long cnt = 0;
	long long now;
	while (index < a.size()) {
		now = 0;
		while (index < a.size() && now < m) now += a[index++];
		if (now >= m) cnt++;
	}
	if (cnt >= k + 1) return true;
	return false;
}

int main() {
	long long n, l;
	cin >> n >> l;
	long long k;
	cin >> k;
	vector<long long> a(n);
	rep(i, n) cin >> a[i];
	vector<long long> b(n + 1);
	b[0] = a[0];
	for (int i = 1; i < n; i++) b[i] = a[i] - a[i - 1];
	b[n] = l - a[n - 1];
	long long left = 1, right = l + 1;
	while (right - left > 1) {
		long long mid = (left + right) / 2;
		if (isOK(mid, b, k)) left = mid;
		else right = mid;
	}
	cout << left << endl;
	return 0;
}