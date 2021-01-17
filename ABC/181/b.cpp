#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    long long a, b;
    rep(i, n) {
        cin >> a >> b;
        ans += (a + b)*(b - a + 1) / 2;
    }
    cout << ans << endl;
}