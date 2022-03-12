#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, x;
	cin >> n >> x;
	string s;
	cin >> s;
	vector<char> deque;
	rep(i, n) {
		if (deque.empty()) {
			deque.push_back(s[i]);
			continue;
		}
		if (deque[deque.size() - 1] != 'U') {
			if (s[i] == 'U') deque.pop_back();
			else deque.push_back(s[i]);
		}
		else deque.push_back(s[i]);
	}
	for (char c : deque) {
		if (c == 'U') x /= 2;
		if (c == 'L') x *= 2;
		if (c == 'R') x = 2 * x + 1;
	}
	cout << x << endl;
	return 0;
}