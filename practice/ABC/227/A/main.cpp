#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k, a;
    cin >> n >> k >> a;
    int ans = (a + k - 1) % n;
    if (ans == 0) cout << n << endl;
    else cout << ans << endl;
}