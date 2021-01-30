#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int x;
    cin >> x;
    int ans = 1;
    while (ans * ans * ans * ans != x) {
        ans++;
    }
    cout << ans << endl;
}