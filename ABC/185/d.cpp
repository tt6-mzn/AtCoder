#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());

    if(m == 0) {
        cout << 1 << endl;
        return 0;
    }

    vector<int> d(m + 1);
    d.at(0) = a.at(0) - 1;
    d.at(m) = n - a.at(m - 1);
    rep(i, m - 1) {
        d.at(i + 1) = a.at(i + 1) - a.at(i) - 1;
    }

    int mind = 1100100100;
    rep(i, m + 1) {
        if(d.at(i) != 0) {
            mind = min(mind, d.at(i)); 
        }
    }
    int ans = 0;
    rep(i, m + 1) {
        ans += (d.at(i) + mind - 1) / mind;
    }
    cout << ans << endl;
}