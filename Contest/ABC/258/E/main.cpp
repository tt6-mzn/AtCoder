#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, q, x;
	cin >> n >> q >> x;
	vector<long long> w(n);
	rep(i, n) cin >> w[i];
	long long s = 0;
	rep(i, n) s += w[i];

	vector<long long> G(n), count(n);
	long long sum_w = 0;
	long long c = 0;
	int j = 0;
	rep(i, n) {
		while (sum_w < x % s) {
			sum_w += w[j];
			j = (j + 1) % n;
			c++;
		}
		G[i] = j;
		count[i] = c;
		sum_w -= w[i];
		c--;
	}

	// rep(_, count.size()) { cout << count[_] << " "; } cout << endl;

	map<int, bool> mp;
	int i = 0;
	while (mp[i] == false) {
		mp[i] = true;
		i = G[i];
	}
	j = 0;
	int cnt = 0;
	vector<long long> head;
	while (j != i) {
		head.push_back(count[j]);
		j = G[j];
		cnt++;
	}
	head.push_back(count[j]);
	cnt++;
	j = G[i];
	int t = 1;
	vector<long long> lp;
	lp.push_back(count[i]);
	while (j != i) {
		lp.push_back(count[j]);
		j = G[j];
		t++;
	}

	// rep(_, head.size()) { cout << head[_] << " "; } cout << endl;
	// rep(_, lp.size()) { cout << lp[_] << " "; } cout << endl;

	rep(_, q) {
		long long k;
		cin >> k;
		if (k <= cnt) {
			cout << n * (x / s) + head[k - 1] << endl;
		}
		else {
			k -= cnt;
			cout << n * (x / s) + lp[k % lp.size()] << endl;;
		}
	}
	return 0;
}