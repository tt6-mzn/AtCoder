#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (n % 2 == 0) {
        string t = "";
        rep(i, n / 2) {
            t += s[i];
        }
        if (s == t + t) {
            cout << "Yes" << endl;
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
}