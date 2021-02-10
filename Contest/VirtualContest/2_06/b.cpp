#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<string> s;
    string c;
    while (cin >> c) {
        s.push_back(c);
    }
    rep(i, s.size() - 1) {
        if (s[i] == "Left") {
            cout << "< ";
        }
        else if (s[i] == "Right") {
            cout << "> ";
        }
        else {
            cout << "A ";
        }
    }
    if (s.back() == "Left") {
        cout << "<" << endl;
    }
    else if (s.back() == "Right") {
        cout << ">" << endl;
    }
    else {
        cout << "A" << endl;
    }
}