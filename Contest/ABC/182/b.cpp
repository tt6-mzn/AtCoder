#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a.at(i);

    int max_cnt = -1, ans;
    for(int k = 2; k < 1001; k++) {
        int cnt = 0;
        rep(i, n) {
            if(a.at(i) % k == 0) {
                cnt++;
            }
        }
        if(cnt > max_cnt) {
            max_cnt = cnt;
            ans = k;
        }
    }
    cout << ans << endl;
}