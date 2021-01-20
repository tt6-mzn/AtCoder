#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    map<int, int> counter;
    rep(i, n) {
        counter[a[i]] += 1;
    }
    int ans = 0;
    for (auto x : counter) {
        if (x.first <= x.second) {
            ans += x.second - x.first;
        }
        else {
            ans += x.second;
        }
    }
    cout << ans << endl;
}