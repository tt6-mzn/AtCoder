#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

// long long op_min(long long a, long long b) {
// 	return min(a, b);
// }
// long long e_min() { return 2100100100LL; }

// long long op_max(long long a, long long b) {
// 	return max(a, b);
// }
// long long e_max() { return -1; }


int main() {
	long long n, a, b;
	cin >> n >> a >> b;
	vector<long long> A(n);
	rep(i, n) cin >> A[i];
	priority_queue<long long> max_que;
	rep(i, n) max_que.push(A[i]);
	priority_queue<long long, vector<long long>, greater<long long>> min_que;
	rep(i, n) min_que.push(A[i]);
	
	// if (n == 2) {
	// 	long long x = min_que.top(); min_que.pop();
	// 	long long y = max_que.top(); max_que.pop();
	// 	long long n = (y - x) / (a + b);
	// 	min_que.push(x + a * n);
	// 	max_que.push(y - b * n);
	// 	cout << min_que.top() << endl;
	// 	return 0;
	// }
	
	while (true) {
		long long x = min_que.top(); min_que.pop();
		long long y = max_que.top(); max_que.pop();
		// cout << x << " " << y << endl;
		long long n1 = (min_que.top() - x + a - 1) / a;
		long long n2 = (y - max_que.top() + b - 1) / b;
		long long n3 = (y - x) / (a + b);
		long long n = min(min(n1, n2), n3);
		if (n <= 0) {
			min_que.push(x);
			max_que.push(y);
			break;
		}
		if (x >= y - b * n) {
			min_que.push(x);
			max_que.push(y);
			break;
		}
		// cout << x + a * n << " " << y - b * n << endl;
		min_que.push(x + a * n);
		max_que.push(y - b * n);
	}
	cout << min_que.top() << endl;
	
	// while ((max_que.top() - min_que.top()) / (a + b) > 0) {
	// 	long long n = (max_que.top() - min_que.top()) / (a + b);
	// 	long long y = max_que.top(); max_que.pop();
	// 	long long x = min_que.top(); min_que.pop();
	// 	max_que.push(y - n * b);
	// 	min_que.push(x + n * a);
	// }
	// cout << min_que.top() << endl;
	return 0;
}