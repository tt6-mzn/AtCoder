#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

template <typename T> bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container | k = 0 | k == n 
    if (first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while (first != src) {
        src--;
        if (*src < *(last - 1)) {
            T dest = subset;
            while (*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

int main() {
	int h1, w1; cin >> h1 >> w1;
	vector<vector<int>> a(h1, vector<int>(w1));
	rep(i, h1) rep(j, w1) cin >> a[i][j];
	int h2, w2; cin >> h2 >> w2;
	vector<vector<int>> b(h2, vector<int>(w2));
	rep(i, h2) rep(j, w2) cin >> b[i][j];
	if (h1 < h2 || w1 < w2) {
		cout << "No" << endl;
		return 0;
	}
	vector<int> hc(h1);
	rep(i, h1) hc[i] = i;
	vector<int> wc(w1);
	rep(i, w1) wc[i] = i;
	while (next_combination(hc.begin(), hc.end(), h2)) {
		while (next_combination(wc.begin(), wc.end(), w2)) {
			bool flg = true;
			rep(i, h2) rep(j, w2) {
				if (a[hc[i]][wc[j]] != b[i][j]) flg = false;
			}
			if (flg) {
				cout << "Yes" << endl;
				return 0;
			}
		}
	}
	cout << "No" << endl;
	return 0;
}