#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    n *= 100;
    for (int i = 1; i <= 50000; i++) {
        if (i * 108 - ((i * 108) % 100) == n) {
            cout << i << endl;
            return 0;
        }
    }
    cout << ":(" << endl;
}