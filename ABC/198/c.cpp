#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    int i = 1, ans = 0;
    while (stoll(to_string(i) + to_string(i)) <= n) {
        i++;
        ans++;
    }
    cout << ans << endl;
}