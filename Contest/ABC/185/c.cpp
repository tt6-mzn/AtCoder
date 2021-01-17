#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

string to_oct(int n) {
    string s;
    while(n > 0) {
        s = to_string(n % 8) + s;
        n /= 8;
    }
    return s;
}

int main() {
    int n;
    cin >> n;
    string s;
    int ans = 0;
    for(int i = 1; i <= n; i++) {
        s = to_string(i);
        bool flg = true;
        rep(j, s.size()) {
            if(s.at(j) == '7') {
                flg = false;
            }
        }
        s = to_oct(i);
        rep(j, s.size()) {
            if(s.at(j) == '7') {
                flg = false;
            }
        }
        if(flg) {
            ans++;
        }
    }
    cout << ans << endl;
}