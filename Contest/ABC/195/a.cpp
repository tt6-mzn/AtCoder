#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int m, h;
    cin >> m >> h;
    if (h % m == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}