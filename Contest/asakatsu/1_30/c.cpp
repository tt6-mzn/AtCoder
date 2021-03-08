#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    string s;
    cin >> s;
    int i = 0, j;
    int ans = 0;
    while (i < s.size()) {
        j = i;
        while (j < s.size() && s[j] == s[j + 1]) {
            j++;
        }
        i = j + 1;
        ans++;
    }
    cout << ans - 1 << endl;
}