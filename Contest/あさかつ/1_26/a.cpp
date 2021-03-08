#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

long long gcd(long long m, long long n) {
    if (n == 0)
        return m;
    return gcd(n, m % n);
}

int main() {
    int n;
    cin >> n;
    cout << (2 * n) / (gcd(2, n)) << endl;
}