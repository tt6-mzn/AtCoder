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
	stack<char> st;
	for (int i = n - 1; i >= 0; i--) st.push(s[i]);
	string ans;
	while (!st.empty()) {
		char c = st.top(); st.pop();
		if (c == 'B') {
			if (st.empty()) {
				ans += c;
				continue;
			}
			if (st.top() == 'A') { // A->BBとしてAを作る
				st.pop();
				ans += 'A';
				st.push('B');
			}
			else if (st.top() == 'B') { // BB->AとしてAを作る
				st.pop();
				ans += 'A';
			}
			else {
				ans += c;
			}
		}
		else ans += c;
	}
	cout << ans << endl;
	return 0;
}