#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, x;
    string s;
    cin >> n >> x;
    cin >> s;
    rep(i, n) {
        if(s.at(i) == 'o') {
            x++;
        }
        else {
            x = max(0, x - 1);
        }
    }
    cout << x << endl;
}