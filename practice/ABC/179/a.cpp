#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    if(s.at(s.size() - 1) == 's') {
        cout << s << "es" << endl;
    }
    else {
        cout << s << 's' << endl;
    }
}