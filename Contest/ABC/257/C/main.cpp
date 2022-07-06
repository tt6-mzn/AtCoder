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
	vector<pair<int, int>> people(n);
	int otona = 0, kodomo = 0;
	rep(i, n) {
		int w;
		cin >> w;
		people[i].first = w;
		people[i].second = s[i] - '0';
		if (people[i].second == 1) otona++;
	}
	sort(people.begin(), people.end());

	int ans = -1;
	int i = 0;
	while (i <= n) {
		ans = max(ans, kodomo + otona);
		int j = 1;
		if (i < n && people[i].second == 1) otona--;
		else kodomo++;
		while (i + j < n && people[i].first == people[i + j].first) {
			if (i + j < n && people[i + j].second == 1) otona--;
			else kodomo++;
			j++;
		}
		i = i + j;
	}
	cout << ans << endl;
	return 0;
}