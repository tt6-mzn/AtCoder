#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= c) {
        cout << b + c << endl;
    }
    else {
        cout << a + 2 * b + 1 << endl;
    }
}