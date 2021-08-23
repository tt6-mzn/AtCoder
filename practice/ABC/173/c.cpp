#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int h, w, k;
    cin >> h >> w >> k;
    vector<string> c(h);
    rep(i, h) cin >> c.at(i);
    int b1 = 1 << h, b2 = 1 << w;
    long long ans = 0;
    for(int i = 0; i < b1; i++) {
        for(int j = 0; j < b2; j++) {
            int cnt = 0;
            rep(k, h) {
                rep(l, w) {
                    if(i >> k & 1 && j >> l & 1 && c.at(k).at(l) == '#') {
                        cnt++;
                    }
                }
            }
            if(cnt == k) {
                ans++;
            }
        }
    }
    cout << ans << endl;
}