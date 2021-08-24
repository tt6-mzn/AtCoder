#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n, k;
	cin >> n >> k;
	rep(i, k) {
		if (n % 200 == 0) {
			n /= 200;
		}
		else {
			n = stoll(to_string(n) + "200");
		}
	}
	cout << n << endl;
}