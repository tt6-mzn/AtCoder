#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x;
    cin >> x;
    if (x % 100 == 0) {
        cout << 100 << endl;
    }
    else {
        cout << 100 - (x % 100) << endl;
    }
}