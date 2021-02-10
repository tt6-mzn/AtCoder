#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    double d_x, d_y, d_r;
    cin >> d_x >> d_y >> d_r;
    long long x, y, r;
    x = d_x * 10000;
    y = d_y * 10000;
    r = d_r * 10000;
    long long ans = 0;
    long long i;
    if ((x - r) >= 0) {
        i = ((abs(x - r) + 10000 - 1) / 10000) * 10000;
    }
    else {
        i = ((abs(x - r) / 10000) * (-10000));
    }
    while (i <= x + r) {
        long long u = 100100, d = 0;
        while (u - d > 1) {
            long long m = (u + d) / 2;
            if ((10000 * m) * (10000 * m) <= r * r - (x - r) * (x - r)) {
                d = m;
            }
            else {
                u = m;
            }
        }
        
        i += 10000;
    }
}