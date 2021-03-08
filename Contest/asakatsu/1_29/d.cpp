#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> d;
    int i = 0, j = 1;
    while (i < n && j < n) {
        while (i < n && s[i] == '1') {
            i++;
        }
        j = i + 1;
        while (j < n && s[j] == '0') {
            j++;
        }
        d.push_back(j - i);
        i = j + 1;
    }
    sort(d.begin(), d.end());
    int ans = 0;
    rep(i, k) {
        ans += d[i];
    }
    rep(i, n) {
        if (s[i] == '1') {
            ans++;
        }
    }
    cout << ans << endl;
}