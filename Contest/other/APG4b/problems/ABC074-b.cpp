#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, k, x, ans = 0;
    cin >> n >> k;
    rep(i, n) {
        cin >> x;
        if(2 * x <= 2 * (k - x)) {
            ans += 2 * x;
        }
        else {
            ans += 2 * (k - x);
        }
    }
    cout << ans << endl;
}
