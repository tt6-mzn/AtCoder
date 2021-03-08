#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    vector<int> cnt_ac(n, 0);
    for (int i = 0; i < n - 1; i++) {
        if (s.substr(i, 2) == "AC") {
            cnt_ac[i + 1] = cnt_ac[i] + 1;
        }
        else {
            cnt_ac[i + 1] = cnt_ac[i];
        }
    }
    rep(i, q) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        if (l - 1 >= 0 && s.substr(l - 1, 2) == "AC") {
            cout << cnt_ac[r] - cnt_ac[max(l - 1, 0)] - 1 << endl;
        }
        else {
            cout << cnt_ac[r] - cnt_ac[max(l - 1, 0)] << endl;
        }
    }
}

