#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    vector<int> ss(n + 1); // s[0, r)までの"."の数
    ss[0] = 0; // s[0, 0)までの"."の数
    for (int i = 1; i <= n; i++) {
        if (s[i - 1] == '.') ss[i] = ss[i - 1] + 1;
        else ss[i] = ss[i - 1];
    }
    int r = 1, ans = -1;
    rep(l, n) {
        while (r <= n && ss[r] - ss[l] <= k) r++;
        ans = max(ans, r - l - 1);
    }
    cout << ans << endl;
    return 0;
}