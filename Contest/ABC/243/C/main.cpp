#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n;
	cin >> n;
	vector<tuple<int, int, int>> yxi(n);
	rep(i, n) {
		int x, y;
		cin >> x >> y;
		yxi[i] = make_tuple(y, x, i);
	}
	sort(yxi.begin(), yxi.end());
	string s;
	cin >> s;
	
	int i = 0, j = 0;
	int yj, xj, ji;
	tie(yj, xj, ji) = yxi[j];
	while (i < n)  {
		int yi, xi, ii;
		tie(yi, xi, ii) = yxi[i];
		bool right = false;
		while (j < n && yi == yj) {
			if (!right) {
				if (s[ji] == 'R') right = true;
			}
			else {
				if (s[ji] == 'L') {
					cout << "Yes" << endl;
					return 0;
				}
			}
			j++;
			if (j < n) tie(yj, xj, ji) = yxi[j];
		}
		i = j;
	}
	cout << "No" << endl;
	return 0;
}