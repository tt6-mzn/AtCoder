#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    rep(i, n) {
        if (s.substr(i, n - i) == t.substr(0, n - i)) {
            cout << (i * 2) + (n - i) << endl;
            return 0;
        }
    }
    cout << 2 * n << endl;
}

