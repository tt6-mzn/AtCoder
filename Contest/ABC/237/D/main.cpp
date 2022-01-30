#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int, int>> L(n + 1);
	int head, tail;
	head = 0;
	L[0].first = -1;
	L[0].second = -1;
	for (int i = 1; i <= n; i++) {
		if (s[i - 1] == 'L') {
			if (L[i - 1].first == -1) {
				head = i;
				L[i].first = -1;
				L[i].second = i - 1;
				L[i - 1].first = i;
			}
			else {
				L[L[i - 1].first].second = i;
				L[i].first = L[i - 1].first;
				L[i].second = i - 1;
				L[i - 1].first = i;
			}
		}
		else {
			if (L[i - 1].second == -1) {
				L[i].first = i - 1;
				L[i].second = -1;
				L[i - 1].second = i;
			}
			else {
				L[L[i - 1].second].first = i;
				L[i].second = L[i - 1].second;
				L[i].first = i - 1;
				L[i - 1].second = i;
			}
		}
	}
	vector<int> ans;
	while (head != -1) {
		ans.push_back(head);
		head = L[head].second;
	}
	cout << ans[0];
	for (int i = 1; i < ans.size(); i++) cout << " " << ans[i];
	cout << endl;
	return 0;
}