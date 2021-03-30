#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int x = 0;
    for (char c : s) {
        if (c == 'I') {
            x++;
        }
        else {
            x--;
        }
        ans = max(ans, x);
    }
    cout << ans << endl;
}