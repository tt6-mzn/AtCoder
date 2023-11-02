#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using mint = modint998244353;

int main() {
	int N, X;
	cin >> N >> X;
	vector<int> T(N);
	rep(i, N) cin >> T[i];

	mint N_inv = N;
	N_inv = N_inv.inv();

	vector<mint> p(X + 1);
	p[0] = 1;
	for (int t = 1; t <= X; t++) {
		rep(i, N) {
			if (t - T[i] >= 0) {
				p[t] += p[t - T[i]];
			} else {
				p[t] += 0;
			}
		}
		p[t] *= N_inv;
	}

	mint ans = 0;
	for (int t = max(X - T[0] + 1, 0); t <= X; t++) {
		ans += p[t];
	}
	ans *= N_inv;

	cout << ans.val() << endl;
	
	return 0;
}