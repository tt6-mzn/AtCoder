#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/* isPrime[i] = true => iは素数, 
 * isPrime[i] = false => iは合成数となるようなvectorを返す
 * n: isPrime[n]まで求める
 * O(nloglogn)
*/
vector<bool> Eratostheness(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = false; isPrime[1] = false;
    for (int i = 2; i * i < n + 1; i++) {
        if (!isPrime[i]) continue;
        for (int j = 2 * i; j < n + 1; j += i) isPrime[j] = false;
    }
    return isPrime;
}