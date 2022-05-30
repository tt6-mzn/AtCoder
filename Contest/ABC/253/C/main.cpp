#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long q;
	cin >> q;
	map<long long, long long> mp;
	priority_queue<long long> que_max, que_min;
	rep(_, q) {
		long long order;
		cin >> order;
		if (order == 1) {
			long long x;
			cin >> x;
			mp[x]++;
			que_max.push(x);
			que_min.push(-x);
		}
		if (order == 2) {
			long long x, c;
			cin >> x >> c;
			mp[x] = max(0LL, mp[x] - c);
		}
		if (order == 3) {
			long long max_v, min_v;
			while (mp[que_max.top()] == 0) que_max.pop();
			max_v = que_max.top();
			while (mp[-que_min.top()] == 0) que_min.pop();
			min_v = -que_min.top();
			cout << max_v - min_v << endl;
		}
	}
	return 0;
}