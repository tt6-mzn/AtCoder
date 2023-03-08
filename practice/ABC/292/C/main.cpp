#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	// n未満の約数の個数を数え上げる
	// num_fractor[i]:=iの約数の個数
	vector<int> num_factor(n, 0);

	for (int i = 1; i < n; i++) {
		for (int j = i; j < n; j += i) num_factor[j]++;
	}

	long long ans = 0;
	for (int i = 1; i < n; i++) {
		// AB = i, CD = n - i
		ans += num_factor[i] * num_factor[n - i];
	}

	cout << ans << endl;
	
	return 0;
}