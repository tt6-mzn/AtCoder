#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	
	int ans = 0;
	// ハーバーボッシュ法
	int j = 1;
	while (j <= n) {
		while (j < n && a[j - 1] == a[j]) j++;
		if (j < n) {
			if (a[j - 1] < a[j]) {
				while (j < n && a[j - 1] <= a[j]) j++;
			}
			else {
				while (j < n && a[j - 1] >= a[j]) j++;
			}
		}
		ans++;
		j++;
	}
	cout << ans << endl;
	return 0;
}