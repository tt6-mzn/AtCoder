#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    long long ans = 1, mod = 1000000007;
    for (int i = 1; i <= n; i++) {
        ans = (ans * i) % mod;
    }
    cout << ans << endl;
}
