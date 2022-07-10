#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	vector<vector<pair<long long, long long>>> pe_list(n);
	vector<long long> m_list(n);
	rep(i, n) {
		cin >> m_list[i];
		pe_list[i].resize(m_list[i]);
		rep(j, m_list[i]) cin >> pe_list[i][j].first >> pe_list[i][j].second;
	}
	// cout << "hello" << endl;
	// return 0;
	map<long long, long long> mp;
	rep(i, n) rep(j, m_list[i]) {
		mp[pe_list[i][j].first] = max(mp[pe_list[i][j].first], pe_list[i][j].second);
	}
	long long ans = 0;
	map<long long, bool> id_mp;
	rep(i, n) rep(j, m_list[i]) {
		long long id = 1;
		long long cnt = mp[pe_list[i][j].first] - pe_list[i][j].second;
		rep(_, cnt) id *= pe_list[i][j].first;
		if (id_mp[id] == false) {
			id_mp[id] = true;
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}