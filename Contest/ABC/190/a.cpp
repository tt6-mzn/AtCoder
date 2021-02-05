#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a != b) {
        if (a > b) {
            cout << "Takahashi" << endl;
        }
        else {
            cout << "Aoki" << endl;
        }
    }
    else {
        if (c == 0) {
            cout << "Aoki" << endl;
        }
        else {
            cout << "Takahashi" << endl;
        }
    }
}