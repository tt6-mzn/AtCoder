#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);
    rep(i, n) cin >> a[i];
    long long ans = 0;
    long long s_ai = a[0], s_ai2 = a[0] * a[0];
    for (int i = 1; i < n; i++) {
        ans += (i * a[i] * a[i]) - (2 * a[i] * s_ai) + s_ai2;
        s_ai += a[i];
        s_ai2 += a[i] * a[i];
    }
    cout << ans << endl;
}

