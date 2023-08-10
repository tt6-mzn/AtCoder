#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    long long ans = 0;
    rep(i, n) {
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            ans++;
        }
    }
    cout << ans << endl;
}