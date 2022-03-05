#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint;

int main() {
	mint::set_mod(3);
	string s;
	cin >> s;
	int q;
	cin >> q;
	string abc = "ABC";
	rep(_, q) {
		long long t, k;
		cin >> t >> k;
		k--;
		stack<bool> isEven; 
		while (k > 0 && t > 0) {
			if (k & 1) isEven.push(false);
			else isEven.push(true);
			k /= 2;
			t--;
		}
		mint tt;
		if (s[k] == 'A') tt = t + 0;
		if (s[k] == 'B') tt = t + 1;
		if (s[k] == 'C') tt = t + 2;
		while (!isEven.empty()) {
			if (isEven.top()) tt++;
			else tt--;
			isEven.pop();
		}
		cout << abc[tt.val()] << endl;
	}
	return 0;
}