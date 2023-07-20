#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<pair<int, vector<int>>> products(n);
	for (auto& [price, feature] : products) {
		cin >> price;
		int c; cin >> c;
		feature = vector<int>(c);
		for (auto &f : feature) cin >> f;
	}

	for (auto& [price_i, feature_i] : products) {
		for (auto& [price_j, feature_j] : products) {
			bool flg1 = price_i >= price_j;
			bool flg2 = includes(
				feature_j.begin(), feature_j.end(),
				feature_i.begin(), feature_i.end()
			);
			bool flg3 = includes(
				feature_i.begin(), feature_i.end(),
				feature_j.begin(), feature_j.end()
			);
			if (flg1 && flg2) {
				if (price_i > price_j || !flg3) {
					cout << "Yes" << endl;
					return 0;
				}
			}
		}
	}
	cout << "No" << endl;
	
	return 0;
}