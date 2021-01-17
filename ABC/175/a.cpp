#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    if(s == "RRR") {
        cout << 3 << endl;
    }
    else if(s.at(0)=='R' and s.at(1)=='R') {
        cout << 2 << endl;
    }
    else if(s.at(1)=='R' and s.at(2)=='R') {
        cout << 2 << endl;
    }
    else if(s == "SSS") {
        cout << 0 << endl;
    }
    else {
        cout << 1 << endl;
    }
}