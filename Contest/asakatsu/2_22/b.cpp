#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int r = abs(x - y);
    int d = max(x, y) - r;
    int ans = 0;
    ans += min(2 * c * d, a * d + b * d);
    if (x >= y) {
        ans += min(2 * c * r, a * r);
    }
    else {
        ans += min(2 * c * r, b * r);
    }
    cout << ans << endl;
}
