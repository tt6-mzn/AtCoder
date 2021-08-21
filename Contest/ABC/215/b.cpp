#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	long long n;
	cin >> n;
	long long k = 0;
	long long now = 1;
	while (now * 2 <= n) {
		now *= 2;
		k++;
	}
	cout << k << endl;
}