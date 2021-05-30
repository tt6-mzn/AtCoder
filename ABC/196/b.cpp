#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string x;
    cin >> x;
    string ans = "";
    for (int i = 0; i < x.size() && x[i] != '.'; i++) {
        cout << x[i];
    }
    cout << endl;
}