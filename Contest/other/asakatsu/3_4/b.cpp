#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> count(300010, 0);
    rep(i, n) {
        count[a[i]]++;
    }
    long long ans = 0;
    int i = 0;
    int pre = count[0];
    while (i < 300005 && count[i] > 0) {
        ans += max(0, pre - count[i + 1]) * (i + 1);
        pre = min(count[i + 1], pre);
        i++;
    }
    cout << ans << endl;
}
