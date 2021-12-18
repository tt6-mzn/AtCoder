#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    long long ans = 0, i = 1;
    while (i <= n) {
        long long m = n / i;
        long long k = (n - i * m) / m;
        ans += m * (k + 1);
        i += k + 1;
    }
    cout << ans << endl;
    return 0;
}