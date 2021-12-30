#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long a, b, k;
    cin >> a >> b >> k;
    long long s = a + b;
    // cmb[n][m] = nCm
    vector<vector<long long>> cmb(a + b + 1, vector<long long>(a + b + 1, 1));
    for (long long n = 2; n < a + b + 1; n++) {
        for (long long m = 1; m < n; m++) {
            cmb[n][m] = cmb[n - 1][m - 1] + cmb[n - 1][m];
        }
    }
    long long cnt = 0;
    while (a != 0 && b != 0) {
        if (cmb[a + b - 1][a - 1] >= k) {
            cout << "a";
            a--;
            cnt++;
        }
        else {
            cout << "b";
            k = k - cmb[a + b - 1][a - 1];
            b--;
            cnt++;
        }
    }
    if (a == 0) {
        rep(i, s - cnt) cout << "b";
    }
    else {
        rep(i, s - cnt) cout << "a";
    }
    cout << endl;
    
    return 0;
}