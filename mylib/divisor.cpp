#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long count_divisors(long long n) {
    long long ret = 1, i = 2;
    if (n == 1) return 1;
    while (i * i < n) {
        if (n % i == 0) ret++;
        i++;
    }
    if (i * i == n) return 2 * ret + 1;
    return 2 * ret;
}
