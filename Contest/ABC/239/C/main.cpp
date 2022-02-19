#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	vector<long long> d = {-2, -1, 1, 2};
	for (long long dx : d) {
		for (long long dy : d) {
			long long x = x1 + dx;
			long long y = y1 + dy;
			if (
				   (x - x1) * (x - x1) + (y - y1) * (y - y1) == 5
				&& (x - x2) * (x - x2) + (y - y2) * (y - y2) == 5
			) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}