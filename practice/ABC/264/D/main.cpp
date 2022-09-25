#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	cin >> s;

	queue<string> que;
	map<string, int> mp;
	map<string, bool> memo;

	que.push(s);
	mp[s] = 0;
	memo[s] = true;
	while (1) {
		string now = que.front(); que.pop();
		if (now == "atcoder") {
			cout << mp[now] << endl;
			return 0;
		}
		string next = now;
		rep(i, 6) {
			swap(next[i], next[i + 1]);
			if (!memo[next]) {
				que.push(next);
				mp[next] = mp[now] + 1;
				memo[next] = true;
			}
			swap(next[i], next[i + 1]);
		}
	}
	return 0;
}