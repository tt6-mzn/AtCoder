#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long intpow(long long a, long long b) {
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0) {
        return intpow(a, b / 2) * intpow(a, b / 2);
    }
    else {
        return a * intpow(a, b / 2) * intpow(a, b / 2);
    }
}

int main() {
    cout << intpow(2, 5) << endl;
    cout << intpow(10, 10) << endl;
}