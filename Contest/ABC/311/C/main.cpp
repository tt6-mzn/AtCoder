#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1, -1);
	for (int i = 1; i < n + 1; i++) cin >> a[i];
	map<int, bool> seen;

	int now = 1;
	while (!seen[now]) {
		seen[now] = true;
		now = a[now];
	}

	vector<int> ans;
	seen = map<int, bool>();
	while (!seen[now]) {
		ans.push_back(now);
		seen[now] = true;
		now = a[now];
	}
	
	cout << ans.size() << endl;
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
	cout << endl;
	
	return 0;
}