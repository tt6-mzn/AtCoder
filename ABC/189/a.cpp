#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string c;
    cin >> c;
    if (c[0] == c[1] && c[1] == c[2]) {
        cout << "Won" << endl;
    }
    else {
        cout << "Lost" << endl;
    }
}