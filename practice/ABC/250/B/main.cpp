#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, a, b;
	cin >> n >> a >> b;
	rep(i, n) {
		rep(j, a) {
			rep(ii, n) {
				rep(jj, b) {
					if (i % 2 == 0) {
						if (ii % 2 == 0) {
							cout << ".";
						}
						else {
							cout << "#";
						}
					}
					else {
						if (ii % 2 == 0) {
							cout << "#";
						}
						else {
							cout << ".";
						}
					}
				}
			}
			cout << endl;
		}
	}
	return 0;
}