#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int ans = 0;
    rep(i, 3) {
        int s, e;
        cin >> s >> e;
        ans += s * e;
    }
    ans /= 10;
    cout << ans << endl;
}