#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n), b(n);
    rep(i, n){ 
        cin >> a[i];
        b[i] = a[i] + i + 1;
    }
    map<long long, long long> mp;
    mp[b[0]]++;
    long long ans = 0;
    for (int i = 1; i < n; i++) {
        if (mp[i + 1 - a[i]]) {
            ans += mp[i + 1 - a[i]];
        }
        mp[b[i]]++;
    }
    cout << ans << endl;
}


