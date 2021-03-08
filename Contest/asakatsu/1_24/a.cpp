#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    string t;
    cin >> s;
    cin >> t;
    if (s == "Y") {
        cout << char(toupper(t[0])) << endl;
    }
    else {
        cout << t << endl;
    }
}