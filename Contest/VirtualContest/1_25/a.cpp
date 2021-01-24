#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b;
    cin >> a >> b;
    string s;
    cin >> s;
    int cnt = 0;
    for (char c : s) {
        if (c == '-') {
            cnt += 1;
        }
    }
    if (cnt == 1 && s[a] == '-') {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}