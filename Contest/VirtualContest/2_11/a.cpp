#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string n;
    cin >> n;
    int s = 0;
    rep(i, n.size()) {
        s += n[i] - '0';
    }
    if (s % 9 == 0) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}