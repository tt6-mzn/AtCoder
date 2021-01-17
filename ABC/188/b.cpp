#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];
    int ans = 0;
    rep(i, n) ans += a[i] * b[i];
    cout << (ans == 0 ? "Yes" : "No") << endl;
    return 0;   
}