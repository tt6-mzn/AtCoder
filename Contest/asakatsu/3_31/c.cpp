#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> mp;
    rep(i, n) {
        mp[a[i]]++;
    }
    int ans = 0;
    for (auto p : mp) {
        int a, b;
        tie(a, b) = p;
        if (b >= a) {
            ans += b - a;
        }
        else {
            ans += b;
        }
    }
    cout << ans << endl;
}