#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    if (s.size() == 2) {
        cout << s << endl;
    }
    else {
        reverse(s.begin(), s.end());
        cout << s << endl;
    }
}