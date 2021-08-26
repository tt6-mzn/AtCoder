#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	int now = 0;
	int cnt = 0;
	while (now < n) {
		cnt++;
		now += cnt;
	}
	cout << cnt << endl;
}