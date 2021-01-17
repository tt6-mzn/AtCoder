#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, ans = 0;
    long long d, x, y;
    cin >> n >> d;
    rep(i, n) {
        cin >> x >> y;
        if(d * d >= x * x + y * y) {
            ans++;
        }
    }
    cout << ans << endl;
}