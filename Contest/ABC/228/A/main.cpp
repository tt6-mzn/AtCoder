#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int s, t, x;
    cin >> s >> t >> x;
    if (s < t) {
        if (s <= x && x < t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else {
        if (s <= x || x < t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}