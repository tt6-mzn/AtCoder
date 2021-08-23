#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int a, b, i, r, l, ans = 0;
    cin >> a >> b;
    for(i = a; i < b + 1; i++) {
        r = i % 100;
        l = (i -  r) / 1000;
        l = (l % 10) * 10 + (l - (l % 10)) / 10;
        if(l == r) {
            ans += 1;
        }
    }
    cout << ans << endl;
}
