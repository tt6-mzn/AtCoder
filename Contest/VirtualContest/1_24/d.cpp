#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    rep(i, n) {
        cin >> s[i];
    }
    sort(s.begin(), s.end());
    int q;
    cin >> q;
    vector<int> k(q);
    rep(i, q) cin >> k[i];
}