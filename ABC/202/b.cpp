#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] == '0' || s[i] == '1' || s[i] == '8') {
            cout << s[i];
        }
        else if (s[i] == '6') {
            cout << "9";
        }
        else {
            cout << "6";
        }
    }
    cout << endl;
}