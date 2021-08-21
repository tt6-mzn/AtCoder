#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	string s;
	int k;
	cin >> s >> k;
	sort(s.begin(), s.end());
	int cnt = 0;
	do {
		cnt++;
		if (cnt == k) {
			cout << s << endl;
			return 0;
		}
	} while (next_permutation(s.begin(), s.end()));
}