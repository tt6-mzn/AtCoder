#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	if (108 * n - (108 * n) % 100 < 20600) {
		cout <<  "Yay!" << endl;
	}
	else if (108 * n - (108 * n) % 100 == 20600) {
		cout << "so-so" << endl;
	}
	else {
		cout << ":(" << endl;
	}
}