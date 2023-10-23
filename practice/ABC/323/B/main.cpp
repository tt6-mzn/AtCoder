#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<string> s(n);
	rep(i, n) cin >> s[i];
	vector<pair<int, int>> p(n);
	rep(i, n) {
		p[i].first = i;
		p[i].second = count(s[i].begin(), s[i].end(), 'o');
	}

	sort(
		p.begin(),
		p.end(),
		[](const pair<int, int>& a, const pair<int, int>& b) {
			if (a.second == b.second) {
				return a.first < b.first;
			}
			return a.second >= b.second;
		}
	);

	cout << p[0].first + 1;
	for (int i = 1; i < n; i++) {
		cout << " " << p[i].first + 1;
	}
	cout << endl;
	return 0;
}
