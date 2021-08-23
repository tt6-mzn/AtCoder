#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int n;
    cin >> n;
    int n2 = 1 << n;
    vector<int> a(n2);
    rep(i, n2) cin >> a[i];
    map<int, int> mp;
    rep(i, n2) mp[a[i]] = i + 1;
    queue<int> q;
    rep(i, n2) q.push(a[i]);
    int ans = 0;
    while (q.size() > 1) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        ans = min(x, y);
        q.push(max(x, y));
    }
    cout << mp[ans] << endl;
    return 0;
}