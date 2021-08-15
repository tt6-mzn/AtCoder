#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	if (1 <= n && n <= 125) {
		cout << 4 << endl;
	}
	else if (126 <= n && n <= 211) {
		cout << 6 << endl;
	}
	else {
		cout << 8 << endl;
	}
}