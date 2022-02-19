#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/* エラトステネスの篩
 * isPrime[i] = true => i は素数
 * isPrime[i] = false => i は合成数
 * となるようなvectorを返す.
 * n: isPrime[n]まで求める
 * O(nloglogn)
*/
vector<bool> eratostheness(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i * i < n + 1; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j < n + 1; j += i) isPrime[j] = false;
    }
    return isPrime;
}

int main() {
	long long a, b, c, d;
	cin >> a >> b >> c >> d;
	vector<bool> isPrime = eratostheness(300);
	for (int i = a; i <= b; i++) {
		bool flg = false;
		for (int j = c; j <= d; j++) {
			if (isPrime[i + j]) flg = true;
		}
		if (!flg) {
			cout << "Takahashi" << endl;
			return 0;
		}
	}
	cout << "Aoki" << endl;
	return 0;
}