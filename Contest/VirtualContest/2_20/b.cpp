#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b;
    cin >> a >> b;
    vector<string> pin(10, "x");
    rep(i, a) {
        int t;
        cin >> t;
        pin[t] = ".";
    }
    rep(i, b) {
        int t;
        cin >> t;
        pin[t] = "o";
    }
    cout << pin[7] << " " << pin[8] << " " << pin[9] << " ";
    cout << pin[0] << endl;
    cout << " " << pin[4] << " " << pin[5] << " ";
    cout << pin[6] << endl;
    cout << "  " << pin[2] << " " << pin[3] << endl;
    cout << "   " << pin[1] << endl;
}
