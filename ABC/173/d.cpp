#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());

    long long ans = 0;
    rep(i, n - 1) {
        ans += a.at(i);
    }
    ans += a.at(0);
    cout << ans << endl;
}