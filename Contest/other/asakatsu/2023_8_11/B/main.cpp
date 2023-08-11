#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;

    if (x1 == x2) {
        cout << abs(y1 - y2) + 1 << endl;
    } else if (y1 == y2) {
        cout << abs(x1 - x2) + 1 << endl;
    } else {
        cout << abs(x1 - x2) + abs(y1 - y2) + 1 << endl;
    }
    return 0;
}