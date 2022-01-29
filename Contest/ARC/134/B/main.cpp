#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

char op(char a, char b) {
	return min(a, b);
}

char e() {
	return (char)'z';
}

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	// segtreeの宣言
	vector<char> v(n); rep(i, n) v[i] = s[i];
	segtree<char, op, e> seg(v);

	// 添え字を管理するvector
	vector<vector<int>> index(26);
	rep(i, n) index[s[i] - 'a'].push_back(i);

	// rep(_, index.size()) { rep(__, index[_].size()) { cout << index[_][__] << " "; } cout << endl; }

	int left = 0, right = n;
	while (right - left > 1) {
		// cout << left << " " << right << endl;
		char c = seg.prod(left + 1, right);
		auto it = lower_bound(index[c - 'a'].begin(), index[c - 'a'].end(), right);
		it--;
		int c_index = *it;
		// cout << c << " " << c_index << endl;
		// return 0;
		if (c >= s[left]) {
			left++;
		}
		else {
			// cout << left << " " << c_index << endl;
			swap(s[left], s[c_index]);
			left++;
			right = c_index;
		}
	}
	cout << s << endl;
	return 0;
}