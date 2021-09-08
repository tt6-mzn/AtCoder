#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	string ans = "";
	while (n > 0) {
		if (n % 2 == 0) {
			n /= 2;
			ans += "B";
		}
		else {
			n--;
			ans += "A";
		}
	}
	reverse(ans.begin(), ans.end());
	cout << ans << endl;
}