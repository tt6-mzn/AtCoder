#include <bits/stdc++.h>
#include <atcoder/all>
#include "02.cpp"
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	cout << "init:" << endl;
	State state;
	state.bd[1][1][Wall]++;
	state.bd[1][2][Wall]++;
	state.bd[1][3][Wall]++;
	state.out();
	auto t = state.floodFill(0, 0);
	rep(i, t.size()) {
		rep(j, t[i].size()) {
			if (t[i][j] == INF) printf("** ");
			else printf("%2d ", t[i][j]);
		}
		cout << endl;
	}
	// string ans;
	// vector<string> ene(state.num_pets, "");
	// while (1) {
	// 	state.out();
	// 	cout << "answer: "; cin >> ans;
	// 	cout << "enemy : ";
	// 	rep(i, state.num_pets) cin >> ene[i];
	// 	state.advance(ans, ene);
	// }
	return 0;
}