#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int q;
	cin >> q;
	priority_queue<pair<long long, long long>> pque;
	long long s = 0;
	rep(i, q) {
		int p;
		cin >> p;
		if (p == 1) {
			long long x;
			cin >> x;
			pair<long long, long long> t;
			t.first = (-1) * (x - s);
			t.second = s;
			pque.push(t);
		}
		else if (p == 2) {
			long long x;
			cin >> x;
			s += x;
		}
		else {
			pair<long long, long long> ans;
			ans = pque.top(); pque.pop();
			cout << (-1) * ans.first + ans.second + (s - ans.second) << endl;
		}
	}
}