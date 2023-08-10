#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

map<string, int> mp;

bool cmp(string a, string b) {
    if (a.size() != b.size()) {
        return a.size() < b.size();
    }
    else if (a == b) {
        return false;
    }
    else {
        int i = 0;
        while (a[i] == b[i]) i++;
        return mp[a.substr(i, 1)] < mp[b.substr(i, 1)];
    }
}

int main() {
    rep(i, 10) {
        string b;
        cin >> b;
        mp[b] = i;
    }
    int n;
    cin >> n;
    vector<string> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    rep(i, n) {
        cout << a[i] << endl;
    }
}

