#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> D(n);
    rep(i, n) cin >> D.at(i);

    int ans = 0, max;
    rep(i, n) {
        max = 0;
        rep(i, n) {
            if(D.at(i) > max) max = D.at(i);
        }
        rep(i, n) {
            if(D.at(i) == max) D.at(i) = 0;
        }
        if(max != 0) {
            ans++;
        }
    }
    cout << ans << endl;
}
