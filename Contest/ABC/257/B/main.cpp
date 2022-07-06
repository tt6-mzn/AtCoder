#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, k, q;
	cin >> n >> k >> q;
	vector<int> a(k);
	vector<bool> bd(n, false);
	rep(i, k) {
		cin >> a[i];
		bd[a[i] - 1] = true;
	}
	rep(_, q) {
		int l;
		cin >> l;
		int i = 0, cnt = 0;
		while (cnt < l) {
			if (bd[i]) cnt++;
			i++;
		}
		i--;
		if (i == n - 1) continue;
		if (bd[i + 1]) continue;
		bd[i] = false;
		bd[i + 1] = true;
	}
	vector<int> ans;
	rep(i, n) {
		if (bd[i]) ans.push_back(i + 1);
	}
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
	cout << endl;
}