#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    vector<bool> is_prime(100010, true);
    is_prime[1] = false;
    for (int i = 2; i < 100010; i++) {
        if (is_prime[i]) {
            for (int j = i * 2; j < 100010; j += i) {
                is_prime[j] = false;
            }
        }
    }
    int ans = n;
    while (is_prime[ans] == false) {
        ans++;
    }
    cout << ans << endl;
}