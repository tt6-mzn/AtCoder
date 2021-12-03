#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string a, b;
    cin >> a >> b;
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    rep(i, min(a.size(), b.size())) {
        if ((a[i] - '0') + (b[i] - '0') >= 10) {
            cout << "Hard" << endl;
            return 0;
        }
    }
    cout << "Easy" << endl;
    return 0;
}