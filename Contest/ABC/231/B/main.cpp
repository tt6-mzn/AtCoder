#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    rep(i, n) {
        string s;
        cin >> s;
        mp[s]++;
    }
    int ansi = -1;
    string anss;
    for (auto it = mp.begin(); it != mp.end(); it++) {
        if (it->second > ansi) {
            ansi = it->second;
            anss = it->first;
        }
    }
    cout << anss << endl;
    return 0;
}