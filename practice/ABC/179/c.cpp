#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    long long ans = 0;
    for(int i = 1; i < n + 1; i++) {
        ans += (n - 1) / i;
    }
    cout << ans << endl;
}