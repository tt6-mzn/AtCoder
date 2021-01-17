#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);
    long long ans = 0;
    for(int i = 1; i < n; i++) {
        if(a.at(i - 1) > a.at(i)) {
            ans += a.at(i - 1) - a.at(i);
            a.at(i) = a.at(i - 1);
        }
    }
    cout << ans << endl;
}