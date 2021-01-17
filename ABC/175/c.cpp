#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long x, k, d, m;
    cin >> x >> k >> d;
    x = abs(x);
    if(k < x / d) {
        cout << x - k * d << endl;
    }
    else {
        k -= x / d;
        x = x % d;
        if(k % 2 == 0) {
            cout << x << endl;
        }
        else {
            cout << d - x << endl;
        }
    }
}