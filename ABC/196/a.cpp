#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = -100000;
    for (int x = a; x <= b; x++) {
        for (int y = c; y <= d; y++) {
            ans = max(ans, x - y);
        }
    }
    cout << ans << endl;
}