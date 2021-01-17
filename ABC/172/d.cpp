#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    long long ans = 0;
    for(long long k = 1; k <= n; k++) {
        ans += (n / k) * k * (1 + (n / k));
    }
    cout << ans / 2 << endl;
}