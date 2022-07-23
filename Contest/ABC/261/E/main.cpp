#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int calc(int x, int op, int y) {
	if (op == 1) return x & y;
	else if (op == 2) return x | y;
	else return x ^ y;
}

int main() {
}