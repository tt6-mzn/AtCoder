#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/*
int ktod(int x, int k) {
	int ret = 0;
	int b = 1;
	while (x > 0) {
		ret += b * (x % 10);
		x /= 10;
		b *= k;
	}
	return ret;
}
*/

int ktod(string s, int k) {
	int ret = 0;
	int b = 1;
	for (int i = s.size() - 1; i >= 0; i--) {
		ret += b * (s[i] - '0');
		b *= k;
	}
	return ret;
}

int main() {
	int k;
	cin >> k;
	string a, b;
	cin >> a >> b;
	cout << (long long)stoi(a, nullptr, k) * (long long)stoi(b, nullptr, k) << endl;

	/*
	for (int i = 1; i <= 10; i++) {
		string x;
		cin >> x;
		cout << ktod(x, k) << endl;
	}
	*/
}