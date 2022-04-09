#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

/* i * i <= nを満たす最大のnを, 二分探索で求める
 * O(logn)
 * !!! nが非常に大きい場合mid * midの部分でオーバーフローする。要改善 !!!
*/
long long sqrt_ll(long long n) {
    long long l = 0, r = n;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        if (mid * mid == n) return mid;
        if (mid * mid < n) l = mid;
        else r = mid;
    }
    return l;
}

int main() {
    for (int i = 1; i <= 100; i++) cout << i << " " << sqrt_ll(i) << endl;
    return 0;
}