#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a.at(i);
    rep(i, n) {
        if(a.at(i) == 0) {
            cout << 0 << endl;
            return 0;
        }
    }
    long long ans = 1;
    rep(i, n) {
        if(a.at(i) <= 1000000000000000000 / ans) {
            ans *= a.at(i);
        }
        else {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
}