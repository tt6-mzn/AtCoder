#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    vector<int> p(26);
    rep(i, 26) cin >> p[i];
    for (auto pi : p) {
        cout << (char)((pi - 1) + 'a');
    }
    cout << endl;
    return 0;
}