#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, a, ans = 1000100100, cnt;
    cin >> n;
    rep(i, n) {
        cin >> a;
        cnt = 0;
        while(a % 2 == 0) {
            cnt++;
            a /= 2;
        }
        if(cnt < ans) {
            ans = cnt;
        }
    }
    cout << ans << endl;
}
