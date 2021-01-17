#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long x, y, a, b, ans = 0;
    cin >> x >> y >> a >> b;
    while((double)a * x <= 2e18 && x * a < x + b && x * a < y) {
        x *= a;
        ans++;
    }
    ans += (y - x - 1) / b;
    cout << ans << endl;
}