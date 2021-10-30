#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> b(n, vector<int>(m));
	vector<vector<int>> bi(n, vector<int>(m));
	vector<vector<int>> bj(n, vector<int>(m));
	rep(i, n) {
		rep(j, m) {
			cin >> b[i][j];
			bj[i][j] = b[i][j] % 7 - 1;
			if (bj[i][j] == -1) bj[i][j] = 6;
			bi[i][j] = (b[i][j] - 1) / 7;
		}
	}
	/*
	rep(i, n) {
		rep(j, m) cout << bi[i][j] << "," << bj[i][j] << " ";
		cout << endl;
	}
	*/
	
	rep(i, n) {
		for (int j = 1; j < m; j++) {
			if (bj[i][j] - bj[i][j - 1] != 1) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	rep(j, m) {
		for (int i = 1; i < n; i++) {
			if (bi[i][j] - bi[i - 1][j] != 1) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}