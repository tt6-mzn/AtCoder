#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long r, x, y;
    cin >> r >> x >> y;
    long long d2 = x * x + y * y;
    if (d2 == r * r) cout << 1 << endl;
    else if (d2 <= 4 * r * r) cout << 2 << endl;
    else {
        double d = sqrt((double)(x * x + y * y));
        cout << ceil(d / r) << endl;
    }
}