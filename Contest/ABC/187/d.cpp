#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> t(n);
    long long a, b;
    long long d = 0;
    rep(i, n) {
        cin >> a >> b;
        t.at(i) = 2 * a + b;
        d += a;
    }
    sort(t.begin(), t.end(), greater<long long>());

    long long ans = 0;
    rep(i, n) {
        d -= t.at(i);
        ans += 1;
        if(d < 0) {
            cout << ans << endl;
            return 0;
        }   
    }
}