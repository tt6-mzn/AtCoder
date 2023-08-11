#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a + b == c && a - b == c) {
        cout << "?" << endl;
        return 0;
    }
    if (a + b == c) {
        cout << "+" << endl;
        return 0;
    }
    if (a - b == c) {
        cout << "-" << endl;
        return 0;
    }
    cout << "!" << endl;
    return 0;
}