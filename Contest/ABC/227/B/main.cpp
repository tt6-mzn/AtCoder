#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) cin >> s[i];
    int ans = 0;
    rep(i, n) {
        bool flg = true;
        for (int a = 1; a <= 500; a++) {
            for (int b = a; b <= 500; b++) {
                if (s[i] == 4 * a * b + 3 * a + 3 * b) flg = false;
            }
        }
        if (flg) ans++;
    }
    cout << ans << endl;
}
