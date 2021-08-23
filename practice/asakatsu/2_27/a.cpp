#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int i = 0;
    int ans = 0;
    while (i < n) {
        int j = i + 1;
        while (j < n && s[i] == s[j]) {
            j++;
        }
        i = j;
        ans++;
    }
    cout << ans << endl;
}