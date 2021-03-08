#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long x, y;
    cin >> x >> y;
    if (x % y == 0) {
        cout << -1 << endl;
        return 0;
    }
    int mx = x;
    while (mx > 0 && mx % y == 0) mx += x;
    if (mx > 0) {
        cout << mx << endl;
    }
    else {
        cout << -1 << endl;
    }
}
