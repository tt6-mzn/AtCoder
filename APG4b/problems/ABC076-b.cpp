#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n, k, ans = 1;
    cin >> n >> k;
    rep(i, n) {
        if(ans * 2 <= ans + k) {
            ans = ans * 2;
        }
        else {
            ans = ans + k;
        }
    }
    cout << ans << endl;
}
