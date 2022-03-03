#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long b, c;
    cin >> b >> c;
    long long ans = 0;
    if (b < 0) {
        b *= -1;
        ans++;
    }
    if (b == 0) {
        cout << c / 2 + (c - 1) / 2 + 1 << endl;
        return 0;
    }
    ans += (c - 1) / 2;
    ans += (c - 2) / 2;
    ans += b - max(b - c / 2, (long long)0) + 1;
    ans += b + min((c - 1) / 2 - b, (long long)-1) + 1;
    cout << ans << endl;
}
