#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int m;
    cin >> m;
    if (m < 100) {
        cout << "00" << endl;
    }
    else if (m <= 5000) {
        if (m < 1000) {
            cout << "0" << m / 100 << endl;
        }
        else {
            cout << m / 100 << endl;
        }
    }
    else if (m <= 30000) {
        cout << m / 1000 + 50 << endl;
    }
    else if (m <= 70000) {
        cout << (m / 1000 - 30) / 5 + 80 << endl;
    }
    else {
        cout << "89" << endl;
    }
}