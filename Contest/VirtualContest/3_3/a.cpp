#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int digits_sum(int n) {
    string s = to_string(n);
    int ret = 0;
    rep(i, s.size()) {
        ret += s[i] - '0';
    }
    return ret;
}

int main() {
    int n;
    cin >> n;
    int ans = 1100100100;
    for (int i = 1; i < n; i++) {
        int j = n - i;
        int sum = digits_sum(i) + digits_sum(j);
        ans = min(sum, ans);
    }
    cout << ans << endl;
}