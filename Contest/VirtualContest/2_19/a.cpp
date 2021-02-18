#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (b - a == c - b) {
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}