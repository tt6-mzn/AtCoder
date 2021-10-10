#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int janken(char c1, char c2) {
	if (c1 == c2) return 0;
	if (c1 == 'G' && c2 == 'C') return 1;
	if (c1 == 'C' && c2 == 'P') return 1;
	if (c1 == 'P' && c2 == 'G') return 1;
	return -1;
}

int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(2 * n);
	rep(i, 2 * n) cin >> a[i];
	vector<int> win(2 * n, 0);
	vector<int> member(2 * n);
	rep(i, 2 * n) member[i] = i;
	rep(j, m) {
		rep(i, n) {
			// 2 * i と 2 * i + 1
			int result = janken(a[member[2 * i]][j], a[member[2 * i + 1]][j]);
			if (result == 1) {
				// 2 * iの勝ち
				win[member[2 * i]]++;
			}
			else if (result == -1) {
				// 2 * i + 1の勝ち
				win[member[2 * i + 1]]++;
			}
		}
		vector<pair<int, int>> next(2 * n);
		rep(i, 2 * n) {
			next[i].first = win[i];
			next[i].second = i;
		}
		sort(next.begin(), next.end(), [](const pair<int, int> &l, const pair<int, int> &r) {
			if (l.first != r.first) return l.first > r.first;
			else return l.second <= r.second;
		});
		// rep(i, 2 * n) cout << next[i].first << " " << next[i].second << endl;
		rep(i, 2 * n) {
			member[i] = next[i].second;
		}
		// rep(i, 2 * n) cout << member[i] << " ";
		// cout << endl;
	}
	rep(i, 2 * n) cout << member[i] + 1 << endl;
}