#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    long long a, b, c, d;
    cin >> a >> b;
    cin >> c >> d;
    if(a == c && b == d) {
        cout << 0 << endl;
    }
    else if(a + b == c + d || a - b == c - d || abs(a - c) + abs(b - d) <= 3) {
        cout << 1 << endl;
    }
    else if(abs((d - abs(a - c)) - b) <= 4 || abs((d + abs(a - c)) - b) <= 4 || abs(a - c) + abs(b - d) <= 6) {
        cout << 2 << endl;
    }
    else if((abs(a - c) + abs(b - d)) % 2 == 0) {
        cout << 2 << endl;
    }
    else {
        cout << 3 << endl;
    }
}