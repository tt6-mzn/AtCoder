#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, x, fx = 0;
    cin >> n;
    x = n;
    rep(i, 8) {
        fx += x % 10;
        x /= 10;
    }
    if(n % fx == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
