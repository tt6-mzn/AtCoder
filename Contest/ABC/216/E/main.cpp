#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
 
int main() {
	long long n, k;
	cin >> n >> k;
	priority_queue<long long> a;
	rep(i, n) {
		long long t;
		cin >> t;
		a.push(t);
	}
	long long ans = 0;
	while (k > 0) {
		long long a1, a2;
		a1 = a.top(); a.pop();
		a2 = a.top(); a.pop();
		if (a1 <= 0 && a2 <= 0) break;
		long long d = a1 - a2 + 1;
		d = min(d, k);
		ans += ((2 * a1 - d + 1) * d) / 2;
		k -= d;
		a.push(a1 - d);
		a.push(a2);
	}
	cout << ans << endl;
}