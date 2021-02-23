#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long x, y, a, b;
    cin >> x >> y >> a >> b;
    long long ans = 0;
    while ((double)x * (double)a <= 1e18 && x * a < y && x * a < x + b) {
        x *= a;
        ans++;
    }
    ans += (y - x - 1) / b;
    cout << ans << endl;
}
