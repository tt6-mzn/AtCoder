#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s1, s2;
    cin >> s1 >> s2;
    if (s1 == "##" || s2 == "##") {
        cout << "Yes" << endl;
    }
    else if (s1[0] == '#' && s2[0] == '#') {
        cout << "Yes" << endl;
    }
    else if (s1[1] == '#' && s2[1] == '#') {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
    return 0;
}