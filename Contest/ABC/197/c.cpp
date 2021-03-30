#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    long long bit_n = 1 << (n - 1);
    long long ans = 9223372036854775807LL;
    if (n == 1) {
        cout << a[0] << endl;
        return 0;
    }
    rep(i, bit_n) {
        long long ans_xor = 0;
        long long j = 1;
        long long ans_or = a[0];
        while (j < n) {
            while (j < n && (i >> (j - 1)) & 1) {
                ans_or |= a[j];
                j++;
            }
            ans_xor ^= ans_or;
            ans_or = a[j];
            j++;
            if (j == n) {
                ans_xor ^= ans_or;
            }
        }
        ans = min(ans_xor, ans);
    }
    cout << ans << endl;
}