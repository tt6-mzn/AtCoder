#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> A(n + 1);
    rep(i, n) cin >> A.at(i + 1);

    int now = 1;
    int ans = 0;
    while(ans != n && now != 2) {
        ans++;
        now = A.at(now);
    }
    if(ans == n) cout << -1 << endl;
    else cout << ans << endl;
}
