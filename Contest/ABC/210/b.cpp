#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	rep(i, n) {
		if (s[i] == '1') {
			if (i % 2 == 0) {
				cout << "Takahashi" << endl;
			}
			else {
				cout << "Aoki" << endl;
			}
			return 0;
		}
	}
}