#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long R, G, B, N;
	cin >> R >> G >> B >> N;
	long long ans = 0;
	rep(r, N / R + 1) rep(g, N / G + 1) {
		long long rg = R * r + G * g;
		if (rg > N) continue;
		if ((N - rg) % B == 0) ans++;
	}
	cout << ans << endl;
	return 0;
}