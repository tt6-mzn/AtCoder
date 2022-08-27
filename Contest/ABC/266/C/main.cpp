#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

bool isOk(int x0, int y0, int x1, int y1, int x2, int y2) {
	if (x0 == x1) {
		if (y0 > y1) return x0 < x2;
		else return x2 < x0;
	}
	else {
		if (x0 < x1) {
			return (x1 - x0) * (y2 - y0) >= (y1 - y0) * (x2 - x0);
		}
		else {
			return (x0 - x1) * (y2 - y0) <= (y0 - y1) * (x2 - x0);
		}
	}
}

int main() {
	int ax, ay; cin >> ax >> ay;
	int bx, by; cin >> bx >> by;
	int cx, cy; cin >> cx >> cy;
	int dx, dy; cin >> dx >> dy;
	if (!isOk(ax, ay, bx, by, cx, cy)) { cout << "No" << endl; return 0; }
	if (!isOk(bx, by, cx, cy, dx, dy)) { cout << "No" << endl; return 0; }
	if (!isOk(cx, cy, dx, dy, ax, ay)) { cout << "No" << endl; return 0; }
	if (!isOk(dx, dy, ax, ay, bx, by)) { cout << "No" << endl; return 0; }
	cout << "Yes" << endl;
	return 0;
}